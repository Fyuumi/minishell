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

# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signals.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

/*Structures*/
typedef struct s_env_var //One node = one variable
{
    char                *key; //"PATH"
    char                *value; //"/usr/bin:/bin"
    struct s_env_var    *next;
}   t_env_var;

typedef struct s_env
{
    t_env_var   *vars; //Head of the linked list
    char        **envp_array; //Array used for execve(), can be NULL initially
}   t_env;

typedef struct s_cmd //Each t_cmd represents a segment between pipes
{
    char            **args; //argv: ["ls", "-la", NULL]
    t_redir         *redirs; //List of redirections
    struct s_cmd    *next; //Next command in the pipe
}   t_cmd;

typedef struct s_expand_ctx
{
    t_env   *env; //To solve $VAR
    int     last_status; //To solve $?
}   t_expand_ctx;

/*Global variable signal*/

extern int  g_signal_received;
//Only global allowed. Handles SIGINT and SIGQUIT.

/*In cmd_utils.c*/
char		*get_path(char **envp);
char		*get_cmd_path(char *cmd, char **envp);

/*In Builtins*/
int ft_echo(char **args);
int ft_env(t_env *env);
void ft_sig(void);

#endif
