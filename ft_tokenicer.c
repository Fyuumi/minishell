/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenicer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:34:19 by codespace         #+#    #+#             */
/*   Updated: 2026/05/11 15:51:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// if input == special token, return the token otherwise return NULL
int ft_tokenicer(char *input)
{
    if(input == "&&" || input == "|")
        return(input);
    if(input == ">>" || input == ":")
        return(input);
    return(NULL);
}
