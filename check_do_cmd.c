#include "minishell.h"

void ft_check_do_cmd(char **cmd_input)
{
    int i;

    i = ft_strncmp(cmd_input[0], "echo", (ft_strlen(cmd_input[0]) + 1));
    if(i == 0)
        ft_echo(cmd_input);
      i = ft_strncmp(cmd_input[0], "pwd", (ft_strlen(cmd_input[0]) + 1));
    if(i == 0)
        ft_pwd();
    return;
}