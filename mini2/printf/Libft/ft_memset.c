/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:06:59 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/17 21:28:03 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

// void ft_putchar(char c)
// {
// 	write(1,&c,1);
// }

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
