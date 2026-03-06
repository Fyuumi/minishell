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
    char *input;
    char **cmd_input;

    (void)argc;
    (void)argv;
    (void)envp;

    while (1)
    {
        input = readline("minishell$ ");
        if (!input)
            break;
        if (*input)
            add_history(input);
        //parse and execute the command
        cmd_input = ft_split(input, ' ');
        //printf("Here the input we passed: %s\n", input);
        //printf("First cmd %s second cmd %s\n", cmd_input[0], cmd_input[1]);
        free(input);
    }
}
