/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:05:03 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 15:07:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>

char	string_back(const t_string *s)
{
	return (!!s->length * s->data[s->length - 1]);
}
