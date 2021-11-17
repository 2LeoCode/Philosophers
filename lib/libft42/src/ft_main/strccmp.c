/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strccmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:03:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/26 06:07:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strccmp(const char *s1, const char *s2, int stop)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] != stop && s2[i] != stop && s1[i] == s2[i])
		++i;
	if (s1[i] == stop || s2[i] == stop)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
