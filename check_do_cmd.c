#include "minishell.h"

void ft_check_do_cmd(char **cmd_input, t_env *env)
{
    char	*cmd_path;
    pid_t     pid;
    int		status;
    char **envp;
    //compares your first word of input with the cmds
    //if it matches it resolves
   envp = ft_env_to_envp(env);
    if(ft_strncmp(cmd_input[0], "echo", (ft_strlen(cmd_input[0]) + 1)) == 0)
         ft_echo(cmd_input);
    else if(ft_strncmp(cmd_input[0], "pwd", (ft_strlen(cmd_input[0]) + 1)) == 0)
         ft_pwd();
    else if(ft_strncmp(cmd_input[0], "cd", (ft_strlen(cmd_input[0]) + 1) == 0))
        ft_cd(cmd_input, env);
    else if(ft_strncmp(cmd_input[0], "exit", (ft_strlen(cmd_input[0]) + 1)) == 0)
          exit(1);
    else
      {
        cmd_path = ft_get_cmd_path(cmd_input[0], envp);
        if (cmd_path)
        {
            pid = fork();
            if (pid == 0)
                execve(cmd_path, cmd_input, envp);
            waitpid(pid, &status, 0);
        }
        else
        {
          write(STDOUT_FILENO, "command not found", 17);
          write(STDOUT_FILENO, "\n", 2);
        }
      }
    return;
}