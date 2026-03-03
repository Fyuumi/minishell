/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:32:48 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/19 20:28:18 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (!*little)
	{
		return ((char *)big);
	}
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] != '\0' && i < len && i + little_len <= len)
	{
		j = 0;
		while (big[j + i] == little[j] && little[j] != '\0')
		{
			j++;
			if (j == little_len)
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
