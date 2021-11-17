/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strclen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:01:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/26 15:02:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strclen(const char *s, int stop)
{
	const char	*ptr = s;

	while (*ptr && *ptr != stop)
		++ptr;
	return (ptr - s);
}
