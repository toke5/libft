/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:40:14 by ttakala           #+#    #+#             */
/*   Updated: 2023/12/09 13:52:55 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	initialize_and_validate(t_line *line, int fd, char *buff)
{
	line->len = 0;
	line->capacity = 0;
	line->len_to_append = 0;
	line->bytes_read = 0;
	line->ptr_to_newline_char = NULL;
	line->ptr_to_null_char = NULL;
	line->str = NULL;
	line->line_complete = 0;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	{
		if (fd >= 0 && fd <= MAX_FD)
			buff[0] = '\0';
		return (0);
	}
	return (1);
}

static void	append_to_line(t_line *line, char *buff)
{
	char	*tmp_str;
	int		new_capacity;

	new_capacity = line->len + line->len_to_append + 1;
	if (new_capacity > line->capacity)
	{
		if (BUFFER_SIZE < 24 && line->len_to_append == BUFFER_SIZE)
			new_capacity *= 2;
		tmp_str = malloc(new_capacity);
		if (tmp_str == NULL)
		{
			free(line->str);
			line->str = NULL;
			return ;
		}
		line->capacity = new_capacity;
		ft_memcpy(tmp_str, line->str, line->len);
		free(line->str);
		line->str = tmp_str;
	}
	ft_memcpy(line->str + line->len, buff, line->len_to_append);
	line->len = line->len + line->len_to_append;
	line->str[line->len] = '\0';
}

static void	line_build_handler(t_line *line, char *buff)
{
	size_t	bytes_to_move;

	line->ptr_to_newline_char = ft_strchr(buff, '\n');
	if (line->ptr_to_newline_char)
	{
		line->len_to_append = line->ptr_to_newline_char - buff + 1;
		append_to_line(line, buff);
		bytes_to_move = ft_strlen_null_safe(line->ptr_to_newline_char + 1) + 1;
		ft_memmove(buff, line->ptr_to_newline_char + 1, bytes_to_move);
		line->line_complete = 1;
	}
	else
	{
		line->ptr_to_null_char = ft_strchr(buff, '\0');
		line->len_to_append = line->ptr_to_null_char - buff;
		append_to_line(line, buff);
		buff[0] = '\0';
	}
}

static char	*shrink_and_return(t_line *line)
{
	char	*tmp_str;

	if (line->bytes_read < 0)
	{
		free(line->str);
		line->str = NULL;
	}
	else if (line->len + 1 < line->capacity)
	{
		tmp_str = malloc(line->len + 1);
		if (tmp_str == NULL)
		{
			free(line->str);
			line->str = NULL;
			return (NULL);
		}
		ft_memcpy(tmp_str, line->str, line->len);
		free(line->str);
		line->str = tmp_str;
		line->str[line->len] = '\0';
	}
	return (line->str);
}

char	*get_next_line(int fd)
{
	static char	buff[MAX_FD][BUFFER_SIZE + 1];
	t_line		line;

	if (!initialize_and_validate(&line, fd, buff[fd]))
		return (NULL);
	while (!line.line_complete)
	{
		if (buff[fd][0] == '\0')
		{
			line.bytes_read = read(fd, buff[fd], BUFFER_SIZE);
			if (line.bytes_read <= 0)
			{
				buff[fd][0] = '\0';
				break ;
			}
			buff[fd][line.bytes_read] = '\0';
		}
		line_build_handler(&line, buff[fd]);
		if (line.str == NULL)
			return (NULL);
	}
	return (shrink_and_return(&line));
}
