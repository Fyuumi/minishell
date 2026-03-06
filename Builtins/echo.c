/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:33:14 by cdenaux           #+#    #+#             */
/*   Updated: 2026/03/05 17:40:38 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*function that displays a string
should behave differently if there's a "flag" -n
subject only mentions -n; not -e nor -E
-n => don't add a new line at the end*/

#include "minishell.h"

int ft_echo(char **args)
{
    int i;
    int flag_n;

    if (!args)
        return (0);
    i = 1;
    flag_n = 0;
    while(args[i] && args[i] == '-' && args[i + 1] == 'n')
    {
        flag_n = 1;
        i++;
    }
    while(args[i])
    {
        printf("%s", args[i]);
        if (args[i + 1])
            printf(" ");
        i++;
    }
    if (!flag_n)
        printf("\n");
    return (0);
}