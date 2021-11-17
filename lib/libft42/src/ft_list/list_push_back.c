/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:04:43 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:35:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>
#include <libft.h>

short	list_push_back(t_list *lst, void *data)
{
	t_node	*new_node;

	new_node = ft_malloc(sizeof(t_node));
	if (!new_node)
		return (LIST_FAILURE);
	new_node->data = data;
	new_node->prev = lst->prev;
	new_node->next = lst;
	lst->prev->next = new_node;
	lst->prev = new_node;
	++lst->data;
	return (LIST_SUCCESS);
}
