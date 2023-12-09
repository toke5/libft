/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:50:48 by ttakala           #+#    #+#             */
/*   Updated: 2023/11/06 15:23:07 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	bytes;

	if (count == 0 || size == 0)
	{
		p = malloc(0);
		return (p);
	}
	bytes = count * size;
	if (bytes / size != count)
	{
		return (NULL);
	}
	p = malloc(count * size);
	if (p == NULL)
	{
		return (NULL);
	}
	ft_bzero(p, count * size);
	return (p);
}
