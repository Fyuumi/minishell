/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:57:50 by cdenaux           #+#    #+#             */
/*   Updated: 2025/12/19 12:13:19 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
	{
		ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		return (1);
	}
	px.infile_fd = -1;
	px.outfile_fd = -1;
	px.pipe_fd[0] = -1;
	px.pipe_fd[1] = -1;
	px.ret_pid2 = 0;
	px.envp = envp;
	pipex_init(&px, argv);
	pipex_run(&px, argv);
	pipex_cleanup(&px);
	return (px.ret_pid2);
}
