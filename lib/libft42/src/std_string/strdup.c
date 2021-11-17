/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:06:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 18:41:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	const size_t	len = ft_strlen(s);
	char			*new_s;

	new_s = ft_malloc(sizeof(char) * (len + 1));
	if (new_s)
		ft_memcpy(new_s, s, len + 1);
	return (new_s);
}
