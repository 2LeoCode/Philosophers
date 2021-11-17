/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 03:51:41 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 02:59:00 by crochu           ###   ########.fr       */
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
		while (++i < len)
			ptr[i] = f(s[i]);
	}
	return (ptr);
}
