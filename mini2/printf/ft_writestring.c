/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writestring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:08:12 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/14 20:58:14 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writestring(char *copy, va_list fyuumi, char *Parameters)
{
	int		i;
	int		count;
	int		len;
	char	*digits;

	len = 0;
	i = 0;
	count = 0;
	digits = ft_strdup("dicsxXup%");
	while (copy[i])
	{
		if (copy[i] == '%' && ft_strchr(digits, copy[i + 1]))
		{
			i += 2;
			len += ft_format(Parameters, fyuumi, count);
			count++;
		}
		else
			ft_putchar_fd(copy[i++], 1);
	}
	len += i;
	len -= (count * 2);
	free(digits);
	return (len);
}
