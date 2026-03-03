/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:41:54 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/22 15:41:17 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	size_t	len_s;

	len_s = ft_strlen(s) + 1;
	string = ft_calloc(len_s, sizeof(char));
	if (string == 0)
	{
		return (NULL);
	}
	ft_strlcpy(string, s, len_s);
	return (string);
}
