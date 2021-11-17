/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:17:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/23 14:24:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <errno.h>
#include <stdbool.h>
#include <limits.h>

static const char	g_base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static long	ft_getbasevalue(int c, int base)
{
	int	i = 0;

	while (i < base && ft_toupper(c) != g_base[i])
		++i;
	if (i < base)
		return (i);
	return (-1);
}

static long	ft_overflow_mul(long a, long b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (LONG_MAX / b < a)
			errno = ERANGE;
	}
	else if (LONG_MIN / b > a)
		errno = ERANGE;
	if (errno == ERANGE)
		return (LONG_MAX + (a < 0 || b < 0));
	return (a * b);
}

static long	ft_overflow_add(long a, long b)
{
	if (b < 0)
	{
		if (LONG_MIN - b > a)
			errno = ERANGE;
	}
	else if (LONG_MAX - b < a)
		errno = ERANGE;
	if (errno == ERANGE)
		return (LONG_MAX + (b < 0));
	return (a + b);
}

static long	ft_getnumber(const char **nptr, int base, bool sign)
{
	long	n;
	long	base_value;

	n = 0;
	base_value = ft_getbasevalue(**nptr, base);
	while (errno != ERANGE && base_value != -1)
	{
		if (sign)
			n = ft_overflow_add(ft_overflow_mul(n, base), -base_value);
		else
			n = ft_overflow_add(ft_overflow_mul(n, base), base_value);
		base_value = ft_getbasevalue(*++*nptr, base);
	}
	while (base_value != -1)
		base_value = ft_getbasevalue(*++*nptr, base);
	return (n);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long		first_digit;
	long		n;
	bool		sign;

	if (endptr)
		*endptr = (char *)nptr;
	if (!base)
		base = 10;
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
	n = ft_getnumber(&nptr, base, sign);
	if (endptr && first_digit != -1)
		*endptr = (char *)nptr;
	return (n);
}
