/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_trgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:40:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 14:16:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_types.h>
#include <libft.h>
#include <stdint.h>

t_trgb	*make_trgb(uint8_t t, uint8_t r, uint8_t g, uint8_t b)
{
	t_trgb	*ptr;

	ptr = ft_malloc(sizeof(t_trgb));
	if (ptr)
	{
		ptr->t = t;
		ptr->r = r;
		ptr->g = g;
		ptr->b = b;
	}
	return (ptr);
}
