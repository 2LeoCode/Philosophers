/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbft_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:27:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 02:52:01 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GBFT_INT_H
# define GBFT_INT_H

# include "gbft.h"
# include "listft.h"

# include <stdbool.h>

typedef int	t_gbop();

typedef struct s_chunk {
	bool	is_list;
	void	*ptr;
	t_freef	*free_fun;
}	t_chunk;

int		gb_main(void *data, t_freef *free_fun, t_gbop *op, bool is_list);
int		gbop_clear(t_list *gb, void *data, t_freef *free_fun, bool is_list);
int		gbop_push(t_list *gb, void *data, t_freef *free_fun, bool is_list);
int		gbop_pop(t_list *gb, void *data, t_freef *free_fun, bool dummy);

void	gb_list_destroy(t_list *lst, t_freef *free_fun);

#endif
