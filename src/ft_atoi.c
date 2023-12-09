/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:31:12 by ttakala           #+#    #+#             */
/*   Updated: 2023/11/08 15:46:27 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	long	result;
	long	sign;
	long	temp;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		temp = result;
		result = result * 10 + (*str++ - '0');
		if (temp > result && sign == 1)
			return (-1);
		else if (temp > result && sign == -1)
			return (0);
	}
	return (result * sign);
}

static int	ft_isspace(char c)
{
	if (c == ' ')
	{
		return (1);
	}
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n')
	{
		return (1);
	}
	return (0);
}
