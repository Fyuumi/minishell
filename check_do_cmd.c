#include "minishell.h"

void ft_check_do_cmd(char **cmd_input, t_env *env)
{
    int i;
    int j;

    //compares your first word of input with the cmds
    //if it matches it resolves
    (void)env;
    j = 0;
    i = ft_strncmp(cmd_input[0], "echo", (ft_strlen(cmd_input[0]) + 1));
    if(i == 0)
    {
        ft_echo(cmd_input);
        j = 1;
    }
    i = ft_strncmp(cmd_input[0], "pwd", (ft_strlen(cmd_input[0]) + 1));
    if(i == 0)
    {
        ft_pwd();
        j = 1;
    }
    i = ft_strncmp(cmd_input[0], "exit", (ft_strlen(cmd_input[0]) + 1));
    if(i == 0)
    {
        exit(1);
        j = 1;
    }
    if (j == 0)
    {
        write(STDOUT_FILENO, "command not found", 17);
        write(STDOUT_FILENO, "\n", 2);
    }
    /*
    i = ft_strncmp(cmd_input[0], "cd", (ft_strlen(cmd_input[0]) + 1));
    if(i == 0)
        ft_cd();
    */
    return;
}