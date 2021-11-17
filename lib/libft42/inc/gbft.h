/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:41:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/10 01:50:42 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GBFT_H
# define GBFT_H

# include "libft_types.h"
# include "stringft.h"
# include "listft.h"

# define GB_FAILURE -1
# define GB_SUCCESS 0

typedef void	*t_allocf();

short		gb_push(void *data, t_freef *free_fun);
short		gb_alloc(void *addr, size_t size);
short		gb_construct(void *addr, t_allocf *alloc_fun, void *alloc_param,
				t_freef *free_fun);
void		gb_pop(void);
void		gb_clear(void);

short		gb_alloc_pair(t_pair **addr, void *first, void *second);
short		gb_alloc_vec2(t_vec2 **addr, long x, long y);
short		gb_alloc_vec2f(t_vec2f **addr, double x, double y);
short		gb_alloc_vec3(t_vec3 **addr, long x, long y, long z);
short		gb_alloc_vec3f(t_vec3f **addr, double x, double y, double z);
short		gb_alloc_trgb(t_trgb **addr, t_trgb data);
short		gb_alloc_bgrt(t_bgrt **addr, t_bgrt data);
short		gb_alloc_flex(t_flex **addr, size_t size);

t_list		*gb_list_new(t_freef *free_fun);
t_string	*gb_string_new(size_t cap);
t_string	*gb_string_from(const char *s);
t_string	*gb_string_dup(const t_string *s);

#endif
