/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:59:42 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 15:00:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>

#include <stdbool.h>

bool	string_empty(const t_string *s)
{
	return (!s->length);
}
