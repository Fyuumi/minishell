/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:30:46 by cdenaux           #+#    #+#             */
/*   Updated: 2026/04/22 11:03:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

#include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
#include <errno.h>

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
    struct t_redir         *redirs; //List of redirections
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
void        ft_free_strings(char **args);
char		*ft_get_path(char **envp);
char		*ft_get_cmd_path(char *cmd, char **envp);

/*In Builtins*/
int         ft_env(t_env *env);
int         ft_echo(char **args);
int         ft_env(t_env *env);
void        ft_sig(void);
int         ft_pwd(void);
int         ft_cd(char **args, t_env *env);

//in init_env
char        **ft_env_to_envp(t_env *env);
void ft_env_update(t_env *env, const char *key, const char *value);
t_env       *ft_init_env(char **envp);

//in check_do_cmd
void        ft_check_do_cmd(char **cmd_input, t_env *env);

// in ft_lstsize
int		    ft_lstsize(t_env *env);

#endif
