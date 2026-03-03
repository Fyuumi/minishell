/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:10:05 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/23 13:47:24 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	int				slen;
	unsigned int	i;

	i = 0;
	slen = ft_strlen(s);
	string = (char *)ft_calloc((slen + 1), sizeof(char));
	if (!string)
		return (NULL);
	while (s[i] != '\0')
	{
		string[i] = (*f)(i, s[i]);
		i++;
	}
	string[i] = 0;
	return (string);
}
