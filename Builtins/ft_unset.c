/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:50:16 by codespace         #+#    #+#             */
/*   Updated: 2026/04/23 15:23:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_unset(t_env *env, char *key)
{
    t_env_var *temp;
    t_env_var *past;
    
    if(!key)
        return (1);
    temp = env->vars;
    past = NULL;
    while(temp)
    {
         if (ft_strncmp(temp->key, key, ft_strlen(key)) == 0)
            {
                if (past)
                    past->next = temp->next;
                free(temp ->key);
                free(temp->value);
                temp->next = temp->next->next;
            }
        past = temp;
        temp = temp->next;
    }
    return (0);
}
