/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:19:57 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/18 11:27:24 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n)
{
	uint64_t	*qw_ptr;
	uint8_t		*byte_ptr;

	qw_ptr = (uint64_t *)s;
	while (n >= sizeof(uint64_t))
	{
		*qw_ptr++ = 0;
		n -= sizeof(uint64_t);
	}
	byte_ptr = (uint8_t *)qw_ptr;
	while (n--)
		*byte_ptr++ = 0;
}
