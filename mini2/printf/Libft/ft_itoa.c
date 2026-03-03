/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:16:37 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/25 13:07:47 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*stringset(char *result, int i, int n, int minus)
{
	result[i--] = '\0';
	while (i > (0 + minus))
	{
		result[i--] = n % 10 + '0';
		n /= 10;
	}
	if (minus == 1)
		result[0] = '-';
	result[i] = n % 10 + '0';
	return (result);
}

static int	intcount(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	if (n == -2147483648)
		return (10);
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		minus;

	minus = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && n != -2147483648)
	{
		minus = 1;
		n = -n;
	}
	i = intcount(n) + minus;
	result = (char *)ft_calloc(i + 1, sizeof(char));
	if (!result)
		return (0);
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result = stringset(result, i, n, minus);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int zahl = -623;              // Test-Zahl
// 	char *string = ft_itoa(zahl); // Aufruf der Funktion

// 	if (string)
// 	{
// 		printf("Ergebnis: %s\n", string); // Ausgabe des Strings
// 		free(string);                     // Speicher wieder freigeben
// 	}
// 	else
// 	{
// 		printf("Fehler: ft_itoa gab NULL zurück\n");
// 	}

// 	return (0);
// }