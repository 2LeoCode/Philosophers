/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrcchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:12:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrcchr(const char *s, int c, int stop)
{
	const char	*ptr = s + ft_strlen(s) - 1;

	while (ptr >= s && *ptr != stop && *ptr != c)
		--ptr;
	if (ptr < s || *ptr == stop)
		return (NULL);
	return ((char *)ptr);
}
