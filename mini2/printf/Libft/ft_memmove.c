/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:09:00 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/25 17:37:48 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	if (temp_dest < temp_src || temp_dest == temp_src)
	{
		return (ft_memcpy(temp_dest, temp_src, n));
	}
	while (n-- > 0)
	{
		temp_dest[n] = temp_src[n];
	}
	return ((char *)dest);
}
