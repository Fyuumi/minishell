/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:14:27 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/14 21:12:47 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_paramcount(char *s)
{
	int		i;
	int		count;
	char	*digits;

	digits = ft_strdup("discuxXp%");
	count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '%' && ft_strchr(digits, s[i]))
		{
			count++;
		}
		i++;
	}
	free(digits);
	return (count);
}
