/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:41:27 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/22 13:06:44 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp_m;
	size_t			k;

	k = nmemb * size;
	temp_m = malloc(k);
	if (temp_m == 0)
		return (NULL);
	ft_bzero(temp_m, k);
	return (temp_m);
}
