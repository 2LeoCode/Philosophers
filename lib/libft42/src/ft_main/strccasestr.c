/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strccasestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:50:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 02:58:05 by crochu           ###   ########.fr       */
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
		if (ft_toupper(*haystack) == ft_toupper(*needle)
			&& !ft_strncasecmp(haystack, needle, needle_len))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
