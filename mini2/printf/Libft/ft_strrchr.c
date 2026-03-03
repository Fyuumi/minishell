/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:39:23 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/19 15:47:44 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	m;

	m = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == m)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	if (m == '\0')
	{
		return (((char *)&s[i]));
	}
	return (NULL);
}
