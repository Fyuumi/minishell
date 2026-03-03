/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:32:53 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/03 16:20:38 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			i;

	i = 0;
	string = (unsigned char *)s;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
		{
			return (&string[i]);
		}
		i++;
	}
	return (NULL);
}
// #include "libft.h"
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "Hello, World!";
// 	char	*result1;
// 	char	str2[] = "Hello, World!";
// 	char	*result2;
// 	char	str3[] = "abcdef";
// 	char	str4[] = "Hello\0World!";
// 	char	*result4;
// 	char	str5[] = "123456789";
// 	char	*result5;
// 	char	str6[] = "";
// 	char	*result6;

// 	// Test 1: Einfacher Test, das Zeichen 'c' im String finden
// 	result1 = ft_memchr(str1, 'o', sizeof(str1));
// 	if (result1)
// 	{
// 		printf("Test 1: Gefunden: '%c' an Position %ld\n", *result1, result1
// 			- str1);
// 	}
// 	else
// 	{
// 		printf("Test 1: Zeichen nicht gefunden\n");
// 	}
// 	// Test 2: Zeichen ist nicht im String
// 	result2 = ft_memchr(str2, 'z', sizeof(str2));
// 	if (result2)
// 	{
// 		printf("Test 2: Gefunden: '%c' an Position %ld\n", *result2, result2
// 			- str2);
// 	}
// 	else
// 	{
// 		printf("Test 2: Zeichen nicht gefunden\n");
// 	}
// 	// Test 3: Suche im ersten Teil des Strings
// 	char *result3 = ft_memchr(str3, 'd', 3);
// 		// Suche nur in den ersten 3 Zeichen
// 	if (result3)
// 	{
// 		printf("Test 3: Gefunden: '%c' an Position %ld\n", *result3, result3
// 			- str3);
// 	}
// 	else
// 	{
// 		printf("Test 3: Zeichen nicht gefunden\n");
// 	}
// 	// Test 4: Null-Byte (ASCII 0) im String
// 	result4 = ft_memchr(str4, '\0', sizeof(str4));
// 	if (result4)
// 	{
// 		printf("Test 4: Gefunden: Null-Byte an Position %ld\n", result4 - str4);
// 	}
// 	else
// 	{
// 		printf("Test 4: Null-Byte nicht gefunden\n");
// 	}
// 	// Test 5: Das Zeichen im letzten Abschnitt des Strings
// 	result5 = ft_memchr(str5, '9', sizeof(str5));
// 	if (result5)
// 	{
// 		printf("Test 5: Gefunden: '%c' an Position %ld\n", *result5, result5
// 			- str5);
// 	}
// 	else
// 	{
// 		printf("Test 5: Zeichen nicht gefunden\n");
// 	}
// 	// Test 6: Leerer String
// 	result6 = ft_memchr(str6, 'a', sizeof(str6));
// 	if (result6)
// 	{
// 		printf("Test 6: Gefunden: '%c' an Position %ld\n", *result6, result6
// 			- str6);
// 	}
// 	else
// 	{
// 		printf("Test 6: Zeichen nicht gefunden\n");
// 	}
// 	return (0);
// }
