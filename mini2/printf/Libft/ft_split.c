/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:19:59 by opaulman          #+#    #+#             */
/*   Updated: 2025/06/25 15:57:30 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*freee(char **string, int c)
{
	while (--c >= 0)
		free(string[c]);
	free(string);
	return (0);
}

static int	wcount(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static char	**memfor_s(char const *s, char c, int words, char **fullstring)
{
	int	dword;
	int	word_index;
	int	i;

	i = 0;
	word_index = 0;
	while (s[i] != '\0' && word_index < words)
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		dword = 0;
		while (s[i + dword] != c && s[i + dword] != '\0')
			dword++;
		fullstring[word_index] = ft_calloc(dword + 1, sizeof(char));
		if (!fullstring[word_index])
			return (freee(fullstring, word_index));
		ft_strlcpy(fullstring[word_index++], s + i, dword + 1);
		i += dword;
	}
	fullstring[word_index] = 0;
	return (fullstring);
}

char	**ft_split(char const *s, char c)
{
	char	**fullstring;
	size_t	words;

	if (!s)
		return (0);
	words = wcount(s, c);
	fullstring = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!fullstring)
	{
		return (0);
	}
	return (memfor_s(s, c, words, fullstring));
}

// #include <stdio.h>
// #include <stdlib.h>

// // Prototyp deiner ft_split (anpassen je nach deiner Implementierung)
// char		**ft_split(char const *s, char c);

// int	main(void)
// {
// 	char **result;
// 	int i;

// 	// Testfälle
// 	const char *test_string = "  Hello  world this  is  a test ";
// 	char separator = ' ';

// 	// ft_split aufrufen
// 	result = ft_split(test_string, separator);

// 	// Ergebnis ausgeben
// 	if (!result)
// 	{
// 		printf("ft_split returned NULL\n");
// 		return (1);
// 	}

// 	printf("Result of ft_split:\n");
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("[%d]: \"%s\"\n", i, result[i]);
// 		free(result[i]); // Wichtig: jedes Teilwort freigeben
// 		i++;
// 	}
// 	free(result); // zuletzt das Array selbst freigeben

// 	return (0);
// }

// if (dword == 0)
// 		{
// 			i++;
// 			continue ;
// 		}