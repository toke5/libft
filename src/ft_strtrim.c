/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:59:25 by ttakala           #+#    #+#             */
/*   Updated: 2023/10/31 16:28:54 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	unsigned int	start;
	char			*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (ft_is_in_set(s1[start], set))
		start++;
	len = ft_strlen(s1);
	if (len > start)
	{
		while (ft_is_in_set(s1[len - 1], set))
			len--;
		len = len - start;
	}
	else
		len = 0;
	result = ft_substr(s1, start, len);
	if (result == NULL)
		return (NULL);
	return (result);
}

static int	ft_is_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
