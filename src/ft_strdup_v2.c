/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:01:56 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/09 09:40:56 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_v2(const char *s1)
{
	char	*result;
	size_t	len;

	if (s1 == NULL)
		s1 = "";
	len = ft_strlen(s1);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result = ft_memcpy(result, s1, len + 1);
	return (result);
}
