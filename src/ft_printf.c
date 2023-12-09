/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:01:24 by ttakala           #+#    #+#             */
/*   Updated: 2023/11/15 16:49:59 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	t_ret	ret;

	ret.print_len = 0;
	ret.fail_state = 0;
	i = 0;
	va_start(args, format);
	while (format[i] && ret.fail_state == 0)
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_printf_conversion_handler(args, format[i + 1], &ret);
			i++;
		}
		else
			ft_printf_char(format[i], &ret);
		i++;
	}
	va_end(args);
	if (ret.fail_state < 0)
		return (-1);
	return (ret.print_len);
}

void	ft_printf_conversion_handler(va_list args, char specifier, t_ret *ret)
{
	if (specifier == 'c')
		ft_printf_char(va_arg(args, int), ret);
	else if (specifier == 's')
		ft_printf_str(va_arg(args, char *), ret);
	else if (specifier == 'p')
		ft_printf_ptr(va_arg(args, unsigned long long), ret);
	else if (specifier == 'd' || specifier == 'i')
		ft_printf_nbr(va_arg(args, int), ret);
	else if (specifier == 'u')
		ft_printf_nbr_unsigned(va_arg(args, unsigned int), ret);
	else if (specifier == 'x')
		ft_printf_hex_lowercase(va_arg(args, unsigned int), ret);
	else if (specifier == 'X')
		ft_printf_hex_uppercase(va_arg(args, unsigned int), ret);
	else if (specifier == '%')
		ft_printf_char('%', ret);
}

void	ft_printf_char(int c, t_ret *ret)
{
	if (ret->fail_state < 0)
		return ;
	if (write(1, &c, 1) < 0)
		ret->fail_state = -1;
	else
		ret->print_len++;
}

void	ft_printf_str(char *str, t_ret *ret)
{
	if (str == NULL)
		ft_printf_str("(null)", ret);
	else
	{
		while (*str)
		{
			ft_printf_char(*str, ret);
			str++;
		}
	}
}