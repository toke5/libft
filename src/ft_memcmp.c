/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:55:23 by ttakala           #+#    #+#             */
/*   Updated: 2023/10/26 14:13:26 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uns1;
	unsigned char	*uns2;

	uns1 = (unsigned char *)s1;
	uns2 = (unsigned char *)s2;
	while (n-- != 0)
	{
		if (*uns1 != *uns2)
		{
			return ((int)(*uns1 - *uns2));
		}
		uns1++;
		uns2++;
	}
	return (0);
}
