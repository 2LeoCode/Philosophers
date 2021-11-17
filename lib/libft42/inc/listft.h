/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:33:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 20:32:31 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTFT_H
# define LISTFT_H

# include <stdint.h>
# include <stddef.h>

# define LIST_FAILURE -1
# define LIST_SUCCESS 0

typedef struct s_node	t_node;
typedef struct s_node	t_list;

typedef void			t_freef();
typedef int				t_cmpf();
typedef int				t_opf();

struct s_node {
	void		*data;
	t_node		*prev;
	t_node		*next;
};

void	list_init(t_list *lst);
void	list_destroy(t_list *lst, t_freef free_fun);

short	list_push_front(t_list *lst, void *data);
short	list_push_back(t_list *lst, void *data);

short	list_insert_before(t_list *lst, t_node *pos, void *data);
short	list_insert_after(t_list *lst, t_node *pos, void *data);

void	*list_pop_front(t_list *lst);
void	*list_pop_back(t_list *lst);

void	*list_pop(t_list *lst, t_node *node);

void	list_sort(t_list *lst, t_cmpf *cmp_fun, void *cmp_param);

void	list_merge(t_list *dst, t_list *src);
void	list_merge_sorted(t_list *dst, t_list *src, t_cmpf *cmp_fun,
			void *cmp_param);

int		list_apply(t_list *lst, t_opf *op_fun, void *op_param);

size_t	list_size(const t_list *lst);

#endif
