/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:28:23 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/14 19:13:48 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static inline void
	ft_copy_chunks(unsigned char **dst, const unsigned char **src, size_t n)
{
	unsigned long		*d;
	const unsigned long	*s;

	d = (unsigned long *)*dst;
	s = (const unsigned long *)*src;
	*dst = *dst + n * sizeof(long);
	*src = *src + n * sizeof(long);
	while (n--)
		*d++ = *s++;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				chunks;
	unsigned int		trail;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (n == 0 || dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	chunks = n / sizeof(long);
	trail = n % sizeof(long);
	if (chunks)
		ft_copy_chunks(&d, &s, chunks);
	while (trail--)
		*d++ = *s++;
	return (dst);
}
