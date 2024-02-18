/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:55:23 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/18 10:38:51 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const uint64_t	*qw1 = s1;
	const uint64_t	*qw2 = s2;
	const uint8_t	*uns1;
	const uint8_t	*uns2;

	while (n >= sizeof(uint64_t))
	{
		if (*qw1 != *qw2)
			break ;
		qw1++;
		qw2++;
		n -= sizeof(uint64_t);
	}
	uns1 = (const uint8_t *)qw1;
	uns2 = (const uint8_t *)qw2;
	while (n > 0)
	{
		if (*uns1 != *uns2)
			return ((int)(*uns1 - *uns2));
		uns1++;
		uns2++;
		n--;
	}
	return (0);
}
