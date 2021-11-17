/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:11:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/26 15:43:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strcchr(const char *s, int c, int stop)
{
	while (*s && *s != stop && *s != c)
		++s;
	if (!*s || *s == stop)
		return (NULL);
	return ((char *)s);
}
