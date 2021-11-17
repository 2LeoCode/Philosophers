/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:07:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:26:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <listft.h>

static int	apply(void *data, t_opf *op_fun, void *op_param)
{
	if (op_param)
		return (op_fun(data, op_param));
	return (op_fun(data));
}

int	list_apply(t_list *lst, t_opf *op_fun, void *op_param)
{
	t_node	*ptr;
	int		ret;

	ptr = lst->next;
	while (ptr != lst)
	{
		ret = apply(ptr->data, op_fun, op_param);
		if (ret)
			return (ret);
	}
	return (LIST_SUCCESS);
}
