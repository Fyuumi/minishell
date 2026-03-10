/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:30:46 by cdenaux           #+#    #+#             */
/*   Updated: 2026/03/03 16:54:38 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft.h"

/*In cmd_utils.c*/
char		*get_path(char **envp);
char		*get_cmd_path(char *cmd, char **envp);

/*In Builtins*/
int ft_echo(char **args);
void sig(void); // in exit.c

#endif
