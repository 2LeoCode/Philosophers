/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stpccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 05:53:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 18:20:15 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_stpccpy(char *dst, const char *src, int stop)
{
	size_t	i;

	i = ~0;
	while (src[++i] && src[i] != stop)
		dst[i] = src[i];
	return (dst + i);
}
