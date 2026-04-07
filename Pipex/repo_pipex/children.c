/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:07:55 by cdenaux           #+#    #+#             */
/*   Updated: 2025/12/29 17:40:45 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *px, char *cmd)
{
	if (dup2(px->infile_fd, STDIN_FILENO) == -1)
		error_exit(px, "dup2 infile_fd -> stdin failed", 1);
	if (dup2(px->pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit(px, "dup2 pipe write end -> stdout failed", 1);
	pipex_cleanup(px);
	exec_cmd(px, cmd);
	exit(1);
}

void	second_child(t_pipex *px, char *cmd)
{
	if (dup2(px->pipe_fd[0], STDIN_FILENO) == -1)
		error_exit(px, "dup2 pipe read end -> stdin failed", 1);
	if (dup2(px->outfile_fd, STDOUT_FILENO) == -1)
		error_exit(px, "dup2 outfile_fd -> stdout failed", 1);
	pipex_cleanup(px);
	exec_cmd(px, cmd);
	exit(1);
}
