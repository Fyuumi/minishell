/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:39:45 by cdenaux           #+#    #+#             */
/*   Updated: 2026/03/03 16:01:31 by cdenaux          ###   ########.fr       */
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

int main(void)
{
    char *input;

    while (1)
    {
        input = readline("minishell$ ");
        if (!input)
            break;
        if (*input)
            add_history(input);
        //parse and execute the command
        printf("Here the input we passed: %s\n", input);
        free(input);
    }
}
