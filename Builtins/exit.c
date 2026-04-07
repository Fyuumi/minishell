#include "minishell.h"

sig_atomic_t	g_sig = 0;

void	ctrl_c(int signal)
{
	(void)signal;
	g_sig = 1;
	write(1, "\n", 1);
	// still in progress
}
void	sig(void)
{
	signal(SIGQUIT, SIG_IGN); // stops control c from closing
	signal(SIGINT, ctrl_c);   // gives control c a new thing to do
}