/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:19:35 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/12 00:02:55 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>

static t_chunk	*make_chunk(void *data, t_freef *free_fun, bool is_list)
{
	t_chunk	*ptr;
	
	ptr = ft_malloc(sizeof(t_chunk));
	if (ptr)
	{
		ptr->is_list = is_list;
		ptr->ptr = data;
		ptr->free_fun = free_fun;
	}
	return (ptr);
}

int	gbop_clear(t_list *gb, void *data, t_freef *free_fun, bool is_list)
{
	t_node	*tmp;
	t_node	*ptr;
	t_chunk	*elem_ptr;

	ptr = gb->next;
	while (ptr != gb)
	{
		elem_ptr = ptr->data;
		if (elem_ptr->is_list)
			gb_list_destroy(gb, elem_ptr->free_fun);
		else if (elem_ptr->free_fun)
			((t_freef *)elem_ptr->free_fun)(elem_ptr->ptr);
		ft_free(elem_ptr);
		tmp = ptr->next;
		ft_free(ptr);
		ptr = tmp;
	}
	gb->data = NULL;
	gb->next = gb;
	gb->prev = gb;
	if (is_list)
		gb_list_destroy(data, free_fun);
	else if (free_fun)
		free_fun(data);
	return (GB_SUCCESS);
}

int	gbop_push(t_list *gb, void *data, t_freef *free_fun, bool is_list)
{
	t_chunk	*elem;

	elem = make_chunk(data, free_fun, is_list);
	if (elem && !list_push_front(gb, elem))
		return (GB_SUCCESS);
	gbop_clear(gb, data, free_fun, is_list);
	return (GB_FAILURE);
}

int	gbop_pop(t_list *gb, void *data, t_freef *free_fun, bool dummy)
{
	t_chunk	*ptr;

	(void)data;
	(void)free_fun;
	(void)dummy;
	ptr = list_pop_front(gb);
	if (ptr)
	{
		if (ptr->free_fun)
			ptr->free_fun(ptr->ptr);
		ft_free(ptr);
	}
	return (GB_SUCCESS);
}

int	gb_main(void *data, t_freef *free_fun, t_gbop *op, bool is_list)
{
	static t_list	garbage = {0, (t_node *)&garbage, (t_node *)&garbage};

	return (op(&garbage, data, free_fun, is_list));
}
