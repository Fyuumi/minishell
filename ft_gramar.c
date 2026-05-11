/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gramar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:26:03 by codespace         #+#    #+#             */
/*   Updated: 2026/05/11 15:39:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_gramarcheck(char ** input, char **token_type)
{
    int i;
    
    i = 1; //skiping the first one because it has to be an command;

    while(input[i])
    {
        if ((i % 2) == 0) // everz secound arg has to a special or echo, like "clear && echo "hey" && ls | grep Lib"
        {
             if((ft_tokenicer(token_type[i]) == NULL) && (input[i - 1] != "echo")) //no special token
                return(0); 
        }
    }
}