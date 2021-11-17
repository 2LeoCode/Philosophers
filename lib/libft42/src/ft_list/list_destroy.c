/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:58:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 20:21:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>
#include <libft.h>

void	list_destroy(t_list *lst, t_freef *free_fun)
{
	t_node	*it;
	t_node	*tmp;

	it = lst->next;
	while (it != lst)
	{
		tmp = it->next;
		if (free_fun)
			free_fun(it->data);
		ft_free(it);
		it = tmp;
	}
	lst->data = NULL;
	lst->next = lst;
	lst->next = lst;
}
