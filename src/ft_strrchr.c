/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:35:10 by ttakala           #+#    #+#             */
/*   Updated: 2023/11/10 11:31:18 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	if ((char)c == '\0')
	{
		return ((char *)s + ft_strlen(s));
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			result = (char *)s;
		}
		s++;
	}
	return (result);
}
