/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrnchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:29:13 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 02:58:43 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrnchr(const char *s, size_t n, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (n && i && s[--i] != c)
		--n;
	if (!n || s[i] != c)
		return (NULL);
	return ((char *)s + i);
}
