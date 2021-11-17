/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:56:24 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 18:37:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(const char *s, const char *set)
{
	const size_t	set_len = ft_strlen(set);
	char			*ptr;
	size_t			len;

	while (*s && ft_memchr(set, *s, set_len))
		++s;
	len = ft_strlen(s);
	while (len && ft_memchr(set, s[len - 1], set_len))
		--len;
	ptr = ft_malloc(sizeof(char) * (len + 1));
	if (ptr)
		*ft_stpncpy(ptr, s, len) = 0;
	return (ptr);
}
