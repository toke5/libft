/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:15:36 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/09 09:22:57 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	result = ft_memmove(result, s1, s1_len);
	ft_strlcpy(result + s1_len, s2, s2_len + 1);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (result);
}
