/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeofparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:41 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/14 20:58:47 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_typeofparam(char *s, int size)
{
	int		i;
	int		count;
	char	*output;

	i = 0;
	count = 0;
	output = ft_calloc(size + 1, sizeof(char));
	if (output == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			output[count] = s[i + 1];
			count++;
			i++;
		}
		i++;
	}
	return (output);
}
