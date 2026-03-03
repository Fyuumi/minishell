/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:13:27 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/25 13:15:14 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	ls;
	size_t	li;

	ls = ft_strlen(s1);
	li = ft_strlen(s2);
	string = (char *)ft_calloc(ls + li + 1, sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, ls + 1);
	if (!string)
		return (NULL);
	li = ls + li;
	ft_strlcat(string, s2, li + 1);
	if (!string)
		return (NULL);
	return (string);
}
