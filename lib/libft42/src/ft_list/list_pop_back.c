/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:20:53 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:35:15 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>
#include <libft.h>

void	*list_pop_back(t_list *lst)
{
	t_node	*new_tail;
	void	*ret;

	if (!lst->data)
		return (NULL);
	ret = lst->prev->data;
	new_tail = lst->prev->prev;
	new_tail->next = lst;
	ft_free(lst->prev);
	lst->prev = new_tail;
	--lst->data;
	return (ret);
}
