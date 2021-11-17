/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:01:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:23:30 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>
#include <libft.h>

short	list_push_front(t_list *lst, void *data)
{
	t_node	*new_node;

	new_node = ft_malloc(sizeof(t_node));
	if (!new_node)
		return (LIST_FAILURE);
	new_node->data = data;
	new_node->prev = lst;
	new_node->next = lst->next;
	lst->next->prev = new_node;
	lst->next = new_node;
	++lst->data;
	return (LIST_SUCCESS);
}
