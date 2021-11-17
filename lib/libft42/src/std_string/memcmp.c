/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:51:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 21:19:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *m1, const void *m2, size_t n)
{
	const unsigned char	*s1 = m1;
	const unsigned char	*s2 = m2;
	size_t				i;

	i = 0;
	while (i < n && s1[i] == s2[i])
		++i;
	return ((i != n) * (s1[i] - s2[i]));
}
