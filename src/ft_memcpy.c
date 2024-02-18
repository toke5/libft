/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:28:23 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/18 11:08:33 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const uint64_t	*q_src = (const uint64_t *)src;
	uint64_t		*q_dst;
	const uint8_t	*uns_src;
	uint8_t			*uns_dst;

	if ((!dst && !src) || n == 0 || dst == src)
		return (dst);
	q_dst = (uint64_t *)dst;
	while (n >= sizeof(uint64_t))
	{
		*q_dst++ = *q_src++;
		n -= sizeof(uint64_t);
	}
	uns_src = (const uint8_t *)q_src;
	uns_dst = (uint8_t *)q_dst;
	while (n--)
		*uns_dst++ = *uns_src++;
	return (dst);
}
