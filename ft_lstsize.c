#include "minishell.h"

int ft_lstsize(t_env *env)
{
    t_env_var *temp;
    int count;

    count = 0;
    temp = env->vars;
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    return (count);
}