/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 03:01:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 22:00:15 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdbool.h>

long	ft_atol(const char *s)
{
	long	n;
	bool	sign;

	sign = false;
	while (ft_isspace(*s))
		++s;
	if (*s == '+' || *s == '-')
		sign = *s++ == '-';
	while (ft_isdigit(*s))
	{
		if (sign)
			n = n * 10 - (*s++ - '0');
		else
			n = n * 10 + *s++ - '0';
	}
	return (n);
}
