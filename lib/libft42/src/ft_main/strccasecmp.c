/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strccasecmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:07:50 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:00:12 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strccasecmp(const char *s1, const char *s2, int c)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] != c && s2[i] != c
		&& ft_toupper(s1[i]) == ft_toupper(s2[i]))
		++i;
	if (s1[i] == c || s2[i] == c)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
