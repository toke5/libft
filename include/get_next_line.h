/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:08 by ttakala           #+#    #+#             */
/*   Updated: 2023/12/09 13:52:55 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100 
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

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

char	*get_next_line(int fd);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen_null_safe(const char *str);

#endif