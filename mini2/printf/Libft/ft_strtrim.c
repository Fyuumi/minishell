/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:04:42 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/25 10:10:18 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	if (i >= j)
		return (ft_strdup(""));
	return (ft_substr(s1, i, j - i));
}
