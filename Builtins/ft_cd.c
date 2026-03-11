/*Header*/

#include "minishell.h"

int ft_cd(char **args, t_env *env)
{
//Check if exactly 1 arg is provided (the path)
  if (!args[1] || args[2])
  {
    ft_putendl_fd("Minishell: cd: invalid number of arguments", STDERR_FILENO);
    return (1);
  }
//Attempt to change directory
  if (chdir(args[1]) != 0)
  {
    ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
    ft_putstr_fd(args[1], STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putendl_fd(strerror(errno), STDERR_FILENO);
    return (1);
  }
//Update PWD in environment (optionnal, but recommended) ***** check with struct decisions, I think it's not useful
  char *new_pwd = getcwd(NULL, 0);
  if (new_pwd)
  {
    //Update PWD in environment list
    //(depends on env structure)
    env_update(env, "PWD", new_pwd);
    free(new_pwd);
  }
  return (0);
}
