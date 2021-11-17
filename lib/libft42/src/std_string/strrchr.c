/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:23:54 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/21 19:53:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*end_ptr = s + ft_strlen(s);

	if (!c)
		return ((char *)end_ptr);
	while (--end_ptr >= s && *end_ptr != c)
		continue ;
	if (end_ptr < s)
		return (NULL);
	return ((char *)end_ptr);
}
