/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:19:01 by opaulman          #+#    #+#             */
/*   Updated: 2025/12/05 21:56:27 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int		g_sig;

void	signal_hand(int signal)
{
	if (signal == SIGUSR2)
		g_sig = 1;
}

int	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (1);
		i++;
	}
	return (0);
}

int	send_char(char c, int pid)
{
	unsigned char	mask;
	int				bit;

	bit = 0;
	mask = 0b10000000;
	while (bit < 8)
	{
		g_sig = 0;
		if (c & mask)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		mask >>= 1;
		bit++;
		while (g_sig == 0)
			pause();
	}
	return (1);
}

int	sending(char *msg, int pid)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(msg);
	send_char(msg[i++], pid);
	while (i < len)
	{
		send_char(msg[i], pid);
		i++;
	}
	send_char('\n', pid);
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("./client.c [pid] [message]");
		return (1);
	}
	if (check_pid(argv[1]) == 1)
		return (ft_printf("not a valid pid"));
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	signal(SIGUSR2, signal_hand);
	sending(msg, pid);
}
