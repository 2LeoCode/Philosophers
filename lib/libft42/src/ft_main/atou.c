/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atou.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 05:46:51 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:18:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdbool.h>

unsigned int	ft_atou(const char *s)
{
	unsigned int	n;
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
