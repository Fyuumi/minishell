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
        ft_sig();
        ft_pwd();
        input = readline("minishell$ ");
        if (!input)
            break;
        if (*input)
            add_history(input);
        //parse and execute the command
        cmd_input = ft_split(input, ' ');
        ft_check_do_cmd(cmd_input);
    //  ft_echo(cmd_input);
        free(input);
    }
}
