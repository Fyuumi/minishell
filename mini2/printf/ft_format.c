/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:23:23 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/14 20:57:17 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printd(int c)
{
	char	*s;

	s = ft_itoa(c);
	if (!s)
	{
		return (0);
	}
	ft_putnbr_fd(c, 1);
	c = ft_strlen(s);
	free(s);
	return (c);
}

int	ft_prints(char *s)
{
	int	c;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	c = ft_strlen(s);
	return (c);
}

int	ft_printu(unsigned int u)
{
	int	len;

	len = 0;
	if (u >= 10)
		len = ft_printu(u / 10);
	u = u % 10;
	ft_putchar_fd((u) + '0', 1);
	return (++len);
}

int	ft_format(char *parameter, va_list fyuumi, int count)
{
	if (parameter[count] == 'd' || parameter[count] == 'i')
		return (ft_printd(va_arg(fyuumi, int)));
	if (parameter[count] == 'c')
	{
		ft_putchar_fd(va_arg(fyuumi, int), 1);
		return (1);
	}
	if (parameter[count] == 's')
		return (ft_prints(va_arg(fyuumi, char *)));
	if (parameter[count] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (parameter[count] == 'u')
		return (ft_printu(va_arg(fyuumi, unsigned int)));
	if (parameter[count] == 'x' || parameter[count] == 'X'
		|| parameter[count] == 'p')
		return (ft_hex(fyuumi, parameter, count));
	return (0);
}
