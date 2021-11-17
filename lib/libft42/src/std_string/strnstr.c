/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:58:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 21:19:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	const size_t	needle_len = ft_strlen(needle);
	size_t			i;

	if (!*needle && n)
		return ((char *)haystack);
	if (n < needle_len)
		return (NULL);
	n -= needle_len;
	i = 0;
	while (i <= n)
	{
		if (haystack[i] == *needle
			&& !ft_strncmp(haystack + i, needle, needle_len))
			return ((char *)haystack + i);
	}
	return (NULL);
}
