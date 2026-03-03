/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:30:46 by cdenaux           #+#    #+#             */
/*   Updated: 2026/01/05 13:56:09 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*Pour utiliser fonctions et structure*/
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	int		ret_pid2;
	char	**envp;
}			t_pipex;

/*Dans children*/

void		first_child(t_pipex *px, char *cmd);
void		second_child(t_pipex *px, char *cmd);

/*Dans cmd_utils*/

char		*get_path(char **envp);
char		*get_cmd_path(char *cmd, char **envp);
void		exec_cmd(t_pipex *px, char *cmd);

/*Dans errors*/

void		error_exit(t_pipex *px, const char *msg, int exit_code);
void		free_strtab(char **strtab);

/*Dans ft_printf*/

int			printformat(va_list args, char type);
int			ft_printf(const char *format, ...);
int			printf_char(char c);
int			printf_str(char *str);
int			printf_nbr(int n);

/*Dans ft_split*/

char		**ft_split(const char *str, char c);

/*Dans ft_strjoin*/

char		*ft_strjoin(char const *s1, char const *s2);

/*Dans pipex*/

void		pipex_init(t_pipex *px, char **argv);
void		pipex_run(t_pipex *px, char **argv);
void		pipex_cleanup(t_pipex *px);

#endif