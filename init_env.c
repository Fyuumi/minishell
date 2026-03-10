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
        
    }
}