/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:11:43 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/15 11:56:42 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	ret;

	if (s != NULL)
	{
		ret = write(fd, s, ft_strlen(s));
		(void)ret;
	}
}
