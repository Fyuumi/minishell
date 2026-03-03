/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:04:06 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/23 15:52:22 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
	{
		return (ft_strdup(""));
	}
	if (start + len > l)
		len = l - start;
	substring = (char *)ft_calloc(len + 1, sizeof(char));
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
