/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:24:15 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/09 16:08:02 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>

short	gb_push(void *data, t_freef *free_fun)
{
	return (gb_main(data, free_fun, (t_gbop *)gbop_push, false));
}
