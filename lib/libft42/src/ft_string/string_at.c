/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:01:05 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 18:42:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>

char	string_at(const t_string *s, unsigned int index)
{
	if ((size_t)index >= s->length)
		return (0);
	return (s->data[index]);
}
