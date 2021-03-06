/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:03:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:30:55 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcstr(const char *haystack, const char *needle, int stop)
{
	const size_t	needle_len = ft_strlen(needle);

	if (!*needle && *haystack != stop)
		return ((char *)haystack);
	if (stop && ft_strchr(needle, stop))
		return (NULL);
	while (*haystack && *haystack != stop)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
