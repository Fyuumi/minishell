/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:39:45 by cdenaux           #+#    #+#             */
/*   Updated: 2026/03/04 15:09:58 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Goal here:
minishell$ ls -l
minishell$ echo hello
minishell$ pwd
minishell$ nosuchcmd
minishell$ exit
*/

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char     *input;
    char     **cmd_input;
    t_env    *env;

    (void)argc;
    (void)argv;
    env = ft_init_env(envp);
    if (!env)
        return (1);
    cmd_input = NULL;
    while (1)
    {
        ft_pwd();
        ft_sig();
        input = readline("minishell$ ");
        if (!input)
            return(1);
        if(!input[0])
            continue;
        if (*input)
            add_history(input);
        //parse and execute the command
        cmd_input = ft_split(input, ' ');
        ft_check_do_cmd(cmd_input, env);
        free(input);
    }
}
