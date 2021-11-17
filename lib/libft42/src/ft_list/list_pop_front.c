/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:06:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:34:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>
#include <libft.h>

void	*list_pop_front(t_list *lst)
{
	t_node	*new_head;
	void	*ret;

	if (!lst->data)
		return (NULL);
	ret = lst->next->data;
	new_head = lst->next->next;
	new_head->prev = lst;
	ft_free(lst->next);
	lst->next = new_head;
	--lst->data;
	return (ret);
}
