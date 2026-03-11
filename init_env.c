/*HEADER*/

#include "minishell.h"

/*Splits "key=value" into a new t_env_var node.
If there's no '=', value is NULL (e.g. export VAR with no value).*/

static t_env var    *new_env_var(char *envp_entry)
{
    t_env_var   *node;
    char        *sep;

    node = malloc(sizeof(t_env_var));
    if (!node)
        return (NULL);
    sep = ft_strchr(envp_entry, '=');
    if (sep)
    {
        node->key = ft_substr(envp_entry, 0, sep - envp_entry);
        node->value = ft_strdup(sep + 1);
    }
    else
    {
        node->key = ft_strdup(envp_entry);
        node->value = NULL;
    }
    node->next = NULL;
    if (!node->key)
    {
        free(node->value);
        free(node);
        return (NULL);
    }
    return (node);
}

/*Appends a node at the end of the list.*/

static void     append_env_var(t_env *env, t_env_var *node)
{
    t_env_var   *current;

    if (!env->vars)
    {
        env->vars = node;
        return;
    }
    current = env->vars;
    while (current->next)
        current = current->next;
    current->next = node;
}

/*Converts char **envp (from main) into a t_env
envp_array is left NULL : rebuilt on demand before execve() !!!! ***** Nope, need to change that later
Returns NULL on malloc failure.*/

t_env   *init_env(char **envp)
{
    t_env       *env;
    t_env_var   *node;
    int         i;

    env = malloc(sizeof(t_env));
    if (!env)
        return (NULL);
    env->vars = NULL;
    env->envp_array = NULL;
    i = 0;
    while (envp[i])
    {
        node = new_env_var(envp[i]);
        if (!node)
        {
            //free_env(env) **must be coded**
            free(env);
            return (NULL);
        }
        append_env_var(env, node);
        i++;
    }
    return (env);
}
