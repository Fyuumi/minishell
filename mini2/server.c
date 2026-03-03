/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:19:05 by opaulman          #+#    #+#             */
/*   Updated: 2025/12/03 17:36:59 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 500
#include "printf/ft_printf.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void	printstr(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit;
	static pid_t			pid;

	(void)context;
	pid = info->si_pid;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	if (bit == 7)
	{
		bit = 0;
		if (c == '\0')
			ft_printf("\n");
		ft_printf("%c", c);
		c = 0;
	}
	else
		bit++;
	kill(pid, SIGUSR2);
}

int	main(void)

{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_sigaction = printstr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
