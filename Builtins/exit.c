#include "minishell.h"

void	ctrl_c(int signal)
{
	(void)signal;

	write(STDOUT_FILENO, "\n", 1);
	 ft_pwd();
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	// still in progress
}

void	ctrl_d(int signal)
{
	(void) signal;

	exit(1);
}
void	ft_sig(void)
{
	signal(SIGQUIT, SIG_IGN); // stops control c from closing
	signal(SIGINT, ctrl_d);   // control d closing
	signal(SIGINT, ctrl_c);   // gives control c a new thing to do
	
}