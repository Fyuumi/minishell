/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:52:08 by cdenaux           #+#    #+#             */
/*   Updated: 2025/12/22 12:58:40 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	printformat(va_list args, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += printf_char(va_arg(args, int));
	else if (type == 's')
		count += printf_str(va_arg(args, char *));
	else if (type == 'd')
		count += printf_nbr(va_arg(args, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += printformat(args, format[i]);
		}
		else
		{
			printf_char(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	printf_char(char c)
{
	write(2, &c, 1);
	return (1);
}

int	printf_nbr(int n)
{
	int		count;
	long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		printf_char('-');
		count++;
		num = -num;
	}
	if (num >= 10)
	{
		count += printf_nbr(num / 10);
	}
	printf_char((num % 10) + '0');
	count++;
	return (count);
}

int	printf_str(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		s = "(null)";
	while (s[len])
	{
		printf_char(s[len]);
		len++;
	}
	return (len);
}
