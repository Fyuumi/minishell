/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:21:53 by opaulman          #+#    #+#             */
/*   Updated: 2025/10/20 14:55:25 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int main()
// {
// 	char *s;
// 	s = "hey";
// 	char laenge;
// 	laenge = ft_strlen(s);
// 	write(1, laenge, 1);
// 	return(0);
// }