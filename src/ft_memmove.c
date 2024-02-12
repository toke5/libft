/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:39:36 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/12 11:44:14 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d == s || n == 0)
		return (dst);
	if (d > s && d - s < (int)n)
	{
		s = s + n - 1;
		d = d + n - 1;
		while (n--)
			*d-- = *s--;
		return (dst);
	}
	if (s > d && s - d < (int)n)
	{
		while (n--)
			*d++ = *s++;
		return (dst);
	}
	ft_memcpy(dst, src, n);
	return (dst);
}
