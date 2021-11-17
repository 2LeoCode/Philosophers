/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:05:50 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:22:38 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>
#include <libft.h>

short	list_insert_before(t_list *lst, t_node *pos, void *data)
{
	t_node	*new_node;

	new_node = ft_malloc(sizeof(t_node));
	if (!new_node)
		return (LIST_FAILURE);
	new_node->data = data;
	new_node->next = pos;
	new_node->prev = pos->prev;
	pos->prev->next = new_node;
	pos->prev = new_node;
	++lst->data;
	return (LIST_SUCCESS);
}
