/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 05:52:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdbool.h>

unsigned long	ft_atoul(const char *s)
{
	unsigned long	n;
	bool			sign;

	sign = false;
	while (ft_isspace(*s))
		++s;
	if (*s == '+' || *s == '-')
		sign = *s++ == '-';
	while (ft_isdigit(*s))
		n = n * 10 + *s++ - '0';
	if (sign)
		return (-n);
	return (n);
}
