/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcasecmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:36:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 21:20:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strcasecmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && ft_toupper(s1[i]) == ft_toupper(s2[i]))
		++i;
	return ((ft_toupper(s1[i]) == ft_toupper(s2[i]))
		* ((unsigned char)s1[i] - (unsigned char)s2[i]));
}
