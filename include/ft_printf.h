/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:03:54 by ttakala           #+#    #+#             */
/*   Updated: 2023/12/22 14:50:53 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_ret
{
	int	print_len;
	int	fail_state;
}	t_ret;

int		ft_printf(const char *format, ...);
void	ft_printf_conversion_handler(va_list args, char specifier, t_ret *ret);
void	ft_printf_char(int c, t_ret *ret);
void	ft_printf_str(char *str, t_ret *ret);
void	ft_printf_ptr(unsigned long long ptr, t_ret *ret);
void	ft_printf_hex_lowercase(unsigned long long ptr, t_ret *ret);
void	ft_printf_hex_uppercase(unsigned int nbr, t_ret *ret);
void	ft_printf_nbr(long long nbr, t_ret *ret);
void	ft_printf_nbr_unsigned(unsigned int nbr, t_ret *ret);

#endif