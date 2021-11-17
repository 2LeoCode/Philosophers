/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:36:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 20:56:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>

static int	compare(void *a, void *b, t_cmpf cmp_fun, void *cmp_param)
{
	if (cmp_param)
		return (cmp_fun(a, b, cmp_param));
	return (cmp_fun(a, b));
}

void	list_merge_sorted(t_list *dst, t_list *src, t_cmpf *cmp_fun,
			void *cmp_param)
{
	t_node	*ptr;

	list_sort(dst, cmp_fun, cmp_param);
	list_sort(src, cmp_fun, cmp_param);
	ptr = dst->next;
	while (ptr != dst)
	{
		if (compare(ptr->data, src->next->data, cmp_fun, cmp_param) > 0)
		{
			ptr->prev->next = src->next;
			src->next->prev = ptr->prev;
			ptr->prev = src->next;
			src->next = src->next->next;
			src->next->prev = src;
			ptr->prev->next = ptr;
		}
		else
			ptr = ptr->next;
	}
	dst->data += (uintptr_t)src->data;
	src->data = NULL;
}
