/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:53:05 by cdenaux           #+#    #+#             */
/*   Updated: 2025/12/31 16:02:33 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_init(t_pipex *px, char **argv)
{
	px->infile_fd = open(argv[1], O_RDONLY);
	if (px->infile_fd < 0)
	{
		error_exit(px, "issue with infile, no such file or directory", 1);
	}
	px->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile_fd < 0)
	{
		error_exit(px, "issue with outfile opening or creating", 1);
	}
	if (pipe(px->pipe_fd) == -1)
	{
		error_exit(px, "issue with creating pipe", 1);
	}
}

void	pipex_run(t_pipex *px, char **argv)
{
	pid_t	pid1;
	int		status;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		error_exit(px, "Error forking first child", 1);
	if (pid1 == 0)
		first_child(px, argv[2]);
	pid2 = fork();
	if (pid2 < 0)
		error_exit(px, "Error forking second child", 1);
	if (pid2 == 0)
		second_child(px, argv[3]);
	pipex_cleanup(px);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		px->ret_pid2 = WEXITSTATUS(status);
	else
		px->ret_pid2 = 1;
}

void	pipex_cleanup(t_pipex *px)
{
	if (px->infile_fd >= 0)
	{
		close(px->infile_fd);
		px->infile_fd = -1;
	}
	if (px->outfile_fd >= 0)
	{
		close(px->outfile_fd);
		px->outfile_fd = -1;
	}
	if (px->pipe_fd[0] >= 0)
	{
		close(px->pipe_fd[0]);
		px->pipe_fd[0] = -1;
	}
	if (px->pipe_fd[1] >= 0)
	{
		close(px->pipe_fd[1]);
		px->pipe_fd[1] = -1;
	}
}
