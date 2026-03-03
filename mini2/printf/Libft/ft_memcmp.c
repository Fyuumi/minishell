/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:36:17 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/19 16:45:27 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_si;
	unsigned char	*temp_sb;

	i = 0;
	temp_si = (unsigned char *)(s1);
	temp_sb = (unsigned char *)(s2);
	while (i < n)
	{
		if (temp_si[i] != temp_sb[i])
		{
			return (temp_si[i] - temp_sb[i]);
		}
		i++;
	}
	return (0);
}
