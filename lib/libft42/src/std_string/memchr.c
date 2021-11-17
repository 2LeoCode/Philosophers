/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:19:16 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:09:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *m, int c, size_t n)
{
	const char	*s = m;
	size_t		i;

	i = 0;
	while (i < n && s[i] != c)
		++i;
	if (i == n)
		return (NULL);
	return ((void *)(s + i));
}
