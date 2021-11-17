/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bgrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:44:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 14:16:30 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_types.h>
#include <libft.h>
#include <stdint.h>

t_bgrt	*make_bgrt(uint8_t b, uint8_t g, uint8_t r, uint8_t t)
{
	t_bgrt	*ptr;

	ptr = ft_malloc(sizeof(t_bgrt));
	if (ptr)
	{
		ptr->b = b;
		ptr->g = g;
		ptr->r = r;
		ptr->t = t;
	}
	return (ptr);
}
