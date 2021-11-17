/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 03:36:24 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_nlen(unsigned long long n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_ulltoa(unsigned long long n)
{
	const size_t	len = ft_nlen(n);
	char			*ptr;

	ptr = ft_malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		ptr += len;
		*ptr = 0;
		while (n)
		{
			*--ptr = n % 10 + '0';
			n /= 10;
		}
	}
	return (ptr);
}
