/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:50:57 by cdenaux           #+#    #+#             */
/*   Updated: 2025/12/22 16:50:14 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

static size_t	nbr_words(const char *str, char c)
{
	int		i;
	int		in_word;
	size_t	nbr_wrd;

	i = 0;
	nbr_wrd = 0;
	in_word = 0;
	while (str[i])
	{
		if (!(str[i] == c) && in_word == 0)
		{
			in_word = 1;
			nbr_wrd++;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (nbr_wrd);
}

static char	*word_dup(const char *str, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static int	fill_result(char **result, const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] && (str[j] == c))
			j++;
		start = j;
		while (str[j] && !(str[j] == c))
			j++;
		if (j > start)
		{
			result[i] = word_dup(str, start, j);
			if (!result[i])
				return (i);
			i++;
		}
	}
	result[i] = NULL;
	return (-1);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		failed_at;

	if (!str)
		return (NULL);
	result = malloc(sizeof(char *) * (nbr_words(str, c) + 1));
	if (!result)
		return (NULL);
	failed_at = fill_result(result, str, c);
	if (failed_at >= 0)
	{
		ft_free_all(result, failed_at);
		return (NULL);
	}
	return (result);
}
