/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:29:25 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/18 23:15:29 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*s;

	p = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	while ((s2[i] || s1[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((p)[i] - s[i]);
		}
		i++;
	}
	return (0);
}
