/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:34:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/21 19:29:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memrchr(const void *m, int c, size_t n)
{
	const char	*s = m;

	while (n-- && s[n] != c)
		continue ;
	if (!n)
		return (NULL);
	return ((void *)(s + n));
}
