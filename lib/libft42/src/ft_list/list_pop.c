/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:47:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:35:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>
#include <libft.h>

void	*list_pop(t_list *lst, t_node *node)
{
	void	*ret;

	ret = node->data;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	ft_free(node);
	--lst->data;
	return (ret);
}
