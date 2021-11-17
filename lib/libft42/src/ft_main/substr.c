/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:36:05 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:06:57 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);

	if (s_len < start)
		start = s_len;
	s += start;
	return (ft_strndup(s, ft_strnlen(s, len)));
}
