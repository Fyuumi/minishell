/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:41:50 by cdenaux           #+#    #+#             */
/*   Updated: 2026/03/05 18:42:27 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*Helper to display the variable as "key=value\n"
Only displays if there's a value stored
write() instead of printf() to avoid leaks (possible buffer issue with pipes)*/

static void print_env_var(t_env_var *var)
{
    if (!var->value)
        return;
    write(STDOUT_FILENO, var->key, ft_strlen(var->key));
    write(STDOUT_FILENO, "=", 1);
    write(STDOUT_FILENO, var->value, ft_strlen(var->value));
    write(STDOUT_FILENO, "\n", 1);
}


/*Spans the linked list and displays each variable
Return 1 if env is not valid, otherwise 0
no options or arguments as asked in the subject*/

int ft_env(t_env *env)
{
    t_env_var   *current;

    if (!env || !env->vars)
        return (1);
    current = env->vars;
    while (current)
    {
        print_env_var(current);
        current = current->next;
    }
    return (0);
}