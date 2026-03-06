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

#include "minishell.h"

//function that displays a string in the file descriptor
//should behave differently if there's a "flag" -n

int ft_echo(char **args)
{
    int i;
    int flag;

    if (!args)
        return (1);
    i = 1;
    flag = 0;
    while(args[i])
    {
        
    }
}