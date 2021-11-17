/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncasecmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:46:46 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 21:36:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i]
		&& ft_toupper(s1[i]) == ft_toupper(s2[i]))
		++i;
	return ((i != n) * ((unsigned char)s1[i] - (unsigned char)s2[i]));
}
