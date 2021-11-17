/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtoul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:57:02 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/27 16:53:42 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <errno.h>
#include <stdbool.h>

static const char	g_base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static unsigned long	ft_getbasevalue(int c, int base)
{
	int	i = 0;

	while (i < base && ft_toupper(c) != g_base[i])
		++i;
	if (i < base)
		return (i);
	return (~0UL);
}

static unsigned long	ft_getnumber(const char **nptr, int base)
{
	unsigned long	n;
	unsigned long	base_value;

	n = 0;
	base_value = ft_getbasevalue(**nptr, base);
	while (errno != ERANGE && base_value != ~0UL)
	{
		if (((~0UL - base_value) / base) < n) {
			errno = ERANGE;
			n = ~0UL;
		}
		else
			n = n * base + base_value;
		++*nptr;
		base_value = ft_getbasevalue(**nptr, base);
	}
	while (base_value != ~0UL)
		base_value = ft_getbasevalue(*++*nptr, base);
	return (n);
}

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base)
{
	unsigned long	first_digit;
	unsigned long	n;
	bool			sign;

	if (endptr)
		*endptr = (char *)nptr;
	base += 10 * !base;
	if (base < 2 || base > 36)
	{
		errno = EINVAL;
		--*endptr;
		return (0);
	}
	while (ft_isspace(*nptr))
		++nptr;
	sign = (*nptr == '+' || *nptr == '-') && *nptr++ == '-';
	if (base == 16 && !ft_strncasecmp(nptr, "0x", 2))
		nptr += 2;
	first_digit = ft_getbasevalue(*nptr, base);
	n = ft_getnumber(&nptr, base);
	if (endptr && first_digit != ~0UL)
		*endptr = (char *)nptr;
	if (sign)
		n = -n;
	return (n);
}
