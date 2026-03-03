/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:30:50 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/25 13:15:26 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lens;
	size_t	lend;

	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	i = 0;
	if (size <= lend)
		return (lens + size);
	while (i < size - lend - 1 && src[i] != '\0')
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lens + lend);
}
// int	main(void)
// {
// 	char	*str;
// 	char	buff1[0xF00] = "there is no stars in the sky";
// 	char	buff2[0xF00] = "there is no stars in the sky";
// 	size_t	max;

// 	str = "the cake is a lie !\0I'm hidden lol\r\n";
// 	max = strlen("the cake is a lie !\0I'm hidden lol\r\n");
// 	ft_strlcat(buff1, str, max);
// 	printf("ft_strlcat:%s\n", buff1);
// }
