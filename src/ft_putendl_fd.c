/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:16:30 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/15 11:56:38 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	ret;

	if (s != NULL)
	{
		ret = write(fd, s, ft_strlen(s));
		if (ret == -1)
			return ;
		ret = write(fd, "\n", sizeof(char));
		(void)ret;
	}
}
