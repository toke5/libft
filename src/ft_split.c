/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:33:06 by ttakala           #+#    #+#             */
/*   Updated: 2023/11/08 20:29:36 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static int	split_words(char const *s, char c, char **result);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	if (!split_words(s, c, result))
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	result[word_count] = NULL;
	return (result);
}

static int	count_words(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != c)
			s++;
	}
	return (word_count);
}

static int	split_words(char const *s, char c, char **result)
{
	int			i;
	char const	*start_of_word;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start_of_word = s;
			while (*s && *s != c)
				s++;
			result[i] = ft_substr(start_of_word, 0, s - start_of_word);
			if (result[i] == NULL)
			{
				while (--i >= 0)
					free(result[i]);
				return (0);
			}
			i++;
		}
	}
	return (1);
}
