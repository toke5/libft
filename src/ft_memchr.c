/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:32:11 by ttakala           #+#    #+#             */
/*   Updated: 2023/12/22 14:38:42 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uns;

	uns = (unsigned char *)s;
	while (n-- != 0)
	{
		if (*uns == (unsigned char)c)
		{
			return ((void *)uns);
		}
		uns++;
	}
	return (NULL);
}
