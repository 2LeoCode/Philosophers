/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:36:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:33:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>

void	list_merge(t_list *dst, t_list *src)
{
	dst->prev->next = src->next;
	src->next->prev = dst->prev;
	dst->prev = src->prev;
	dst->prev->next = dst;
	src->next = src;
	src->prev = src;
	dst->data += (uintptr_t)src->data;
	src->data = NULL;
}
