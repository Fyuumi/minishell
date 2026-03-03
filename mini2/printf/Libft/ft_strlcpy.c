/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:27:04 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/18 16:09:54 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	p;
	size_t	i;

	p = ft_strlen(src);
	if (size == 0)
	{
		return (p);
	}
	if (dst == NULL || src == NULL)
	{
		return (0);
	}
	p = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (p);
}

// 	int main(void)
// {
//     char src[13] = "Hello World!";
//     char dst[20];

//     ft_strlcpy(dst, src, 13); // 12 Zeichen + '\0'

//     printf("Source: %s\n", src);
//     printf("Dest:   %s\n", dst);

//     return (0);
// }