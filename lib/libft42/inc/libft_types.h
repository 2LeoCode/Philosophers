/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:03:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 14:19:04 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

# include <stddef.h>
# include <stdint.h>

typedef struct s_vec2 {
	long	x;
	long	y;
}	t_vec2;

typedef struct s_vec2f {
	double	x;
	double	y;
}	t_vec2f;

typedef struct s_vec3 {
	long	x;
	long	y;
	long	z;
}	t_vec3;

typedef struct s_vec3f {
	double	x;
	double	y;
	double	z;
}	t_vec3f;

typedef struct s_trgb {
	uint8_t	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_trgb;

typedef struct s_bgrt {
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;
	uint8_t	t;
}	t_bgrt;

typedef struct s_pair {
	void	*first;
	void	*second;
}	t_pair;

typedef struct s_flex {
	size_t	size;
	char	data[];
}	t_flex;

t_trgb	*make_trgb(uint8_t t, uint8_t r, uint8_t g, uint8_t b);
t_bgrt	*make_bgrt(uint8_t b, uint8_t g, uint8_t r, uint8_t t);
t_flex	*make_flex(size_t size);
t_pair	*make_pair(void *first, void *second);
t_vec2	*make_vec2(long x, long y);
t_vec2f	*make_vec2f(double x, double y);
t_vec3	*make_vec3(long x, long y, long z);
t_vec3f	*make_vec3f(double x, double y, double z);

#endif
