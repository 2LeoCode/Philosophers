/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtoll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:51:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/27 16:12:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <errno.h>
#include <stdbool.h>
#include <limits.h>

static const char	g_base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static long long	ft_getbasevalue(int c, int base)
{
	int	i = 0;

	while (i < base && ft_toupper(c) != g_base[i])
		++i;
	if (i < base)
		return (i);
	return (-1);
}

static long long	ft_overflow_mul(long long a, long long b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (LLONG_MAX / b < a)
			errno = ERANGE;
	}
	else if (LLONG_MIN / b > a)
		errno = ERANGE;
	if (errno == ERANGE)
		return (LLONG_MAX + (a < 0 || b < 0));
	return (a * b);
}

static long long	ft_overflow_add(long long a, long long b)
{
	if (b < 0)
	{
		if (LLONG_MIN - b > a)
			errno = ERANGE;
	}
	else if (LLONG_MAX - b < a)
		errno = ERANGE;
	if (errno == ERANGE)
		return (LLONG_MAX + (b < 0));
	return (a + b);
}

static long long ft_getnumber(const char **nptr, int base, bool sign)
{
	long long	n;
	long long	base_value;

	n = 0;
	base_value = ft_getbasevalue(**nptr, base);
	while (errno != ERANGE && base_value != -1)
	{
		if (sign)
			n = ft_overflow_add(ft_overflow_mul(n, base), -base_value);
		else
			n = ft_overflow_add(ft_overflow_mul(n, base), base_value);
		++*nptr;
		base_value = ft_getbasevalue(**nptr, base);
	}
	while (base_value != -1)
		base_value = ft_getbasevalue(*++*nptr, base);
	return (n);
}

long long	ft_strtoll(const char *nptr, char **endptr, int base)
{
	long long	first_digit;
	long long	n;
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
