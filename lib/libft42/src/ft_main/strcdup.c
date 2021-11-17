/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:54:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcdup(const char *s, int stop)
{
	const size_t	len = ft_strclen(s, stop);
	char			*ptr;

	ptr = ft_malloc(sizeof(char) * (len + 1));
	if (ptr)
		*ft_stpncpy(ptr, s, len) = 0;
	return (ptr);
}
