/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:11:35 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/25 12:48:37 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;
	size_t			i;

	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	if ((dest == NULL && temp_src == NULL) || n == 0)
	{
		return (dest);
	}
	i = 0;
	while (n > i)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}

// int main()
// {
// 	size_t n;
// 	const void *src;
// 	void *dest;
// 	ft_memcpy(dest, src, n);
// 	src = "hey";
// 	n = 4;
// 	write (1, ft_memcpy(dest, src, n), n-1);
// 	return(0);
// }
// 	int main(void)
// {
//     char src[] = "Hello World!";
//     char dest[20];
//     ft_memcpy(dest, src, 13); // 12 Zeichen + '\0'
//     printf("Source: %s\n", src);
//     printf("Dest:   %s\n", dest);
//     return (0);
// }