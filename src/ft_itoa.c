/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:01:28 by ttakala           #+#    #+#             */
/*   Updated: 2023/10/27 20:08:59 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long long n);
static char	*ft_llong_to_str(long long n, int length, char *str);

char	*ft_itoa(int n)
{
	char		*str;
	int			is_negative;
	int			length;
	long long	nbr;

	nbr = n;
	is_negative = 0;
	if (nbr < 0)
		is_negative = 1;
	length = ft_count_digits(nbr) + is_negative;
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	str = ft_llong_to_str(nbr, length, str);
	return (str);
}

static int	ft_count_digits(long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_llong_to_str(long long n, int length, char *str)
{
	str[length] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
	{
		str[0] = '0';
	}
	while (n > 0)
	{
		str[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
