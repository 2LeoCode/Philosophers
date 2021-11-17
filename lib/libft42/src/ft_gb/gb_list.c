/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:38:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/09 16:09:41 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <listft.h>
#include <libft.h>

void	gb_list_destroy(t_list *lst, t_freef *free_fun)
{
	list_destroy(lst, free_fun);
	ft_free(lst);
}

t_list	*gb_list_new(t_freef *free_fun)
{
	t_list	*ptr;

	ptr = ft_malloc(sizeof(t_list));
	if (!ptr)
	{
		gb_clear();
		return (NULL);
	}
	list_init(ptr);
	if (gb_main(ptr, free_fun, (t_gbop *)gbop_push, true) == GB_FAILURE)
		return (NULL);
	return (ptr);
}
