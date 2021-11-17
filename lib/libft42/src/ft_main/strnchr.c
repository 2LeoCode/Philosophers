/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:09:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/25 23:29:00 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnchr(const char *s, size_t n, int c)
{
	size_t	i;

	i = 0;
	while (i < n && s[i] && s[i] != c)
		++i;
	if (i == n || s[i] != c)
		return (NULL);
	return ((char *)s + i);
}
