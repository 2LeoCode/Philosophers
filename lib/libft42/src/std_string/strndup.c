/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:11:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/21 19:47:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s, size_t n)
{
	const size_t	len = ft_strnlen(s, n);
	char			*ptr;

	ptr = ft_malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		ft_stpncpy(ptr, s, len);
		ptr[len] = 0;
	}
	return (ptr);
}
