/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:11:23 by ttakala           #+#    #+#             */
/*   Updated: 2024/02/12 15:13:14 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <stdlib.h>
# include <stdint.h>

typedef struct s_vec
{
	unsigned char	*memory;
	size_t			elem_size;
	size_t			alloc_size;
	size_t			len;
}				t_vec;

int		vec_new(t_vec *src, size_t init_len, size_t elem_size);
void	vec_free(t_vec *src);
int		vec_from(t_vec *dst, void *src, size_t len, size_t elem_size);
int		vec_copy(t_vec *dst, t_vec *src);
int		vec_resize(t_vec *src, size_t target_size);

void	*vec_get(t_vec *src, size_t index);
int		vec_push(t_vec *dst, void *src);
int		vec_pop(void *dst, t_vec *src);
int		vec_insert(t_vec *dst, void *src, size_t index);
int		vec_remove(t_vec *src, size_t index);

int		vec_append(t_vec *dst, t_vec *src);
int		vec_prepend(t_vec *dst, t_vec *src);

#endif