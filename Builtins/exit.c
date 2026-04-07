#include "minishell.h"

void	ctrl_c(int signal)
{
	(void)signal;

	write(1, "\n", 1);
	// still in progress
}
void	ft_sig(void)
{
	signal(SIGQUIT, SIG_IGN); // stops control c from closing
	signal(SIGINT, ctrl_c);   // gives control c a new thing to do
}