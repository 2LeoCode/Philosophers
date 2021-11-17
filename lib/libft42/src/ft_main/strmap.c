/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 03:51:41 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	const size_t	len = ft_strlen(s);
	char			*ptr;
	size_t			i;

	ptr = ft_malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		i = ~0;
		while  (++i < len)
			ptr[i] = f(s[i]);
	}
	return (ptr);
}
