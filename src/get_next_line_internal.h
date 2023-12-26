/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:55:03 by ttakala           #+#    #+#             */
/*   Updated: 2023/12/26 12:10:53 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_INTERNAL_H
# define GET_NEXT_LINE_INTERNAL_H

# include <stdlib.h>

# include "get_next_line.h"

typedef struct s_line
{
	int		len;
	int		capacity;
	int		len_to_append;
	int		bytes_read;
	char	*ptr_to_newline_char;
	char	*ptr_to_null_char;
	char	*str;
	int		line_complete;
}				t_line;

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen_null_safe(const char *str);

#endif