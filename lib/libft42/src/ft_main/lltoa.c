/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 03:28:13 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:00:42 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_nlen(long long n)
{
	size_t	len;

	len = n < 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_lltoa(long long n)
{
	const size_t	len = ft_nlen(n);
	char			*ptr;

	ptr = ft_malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		if (n < 0)
			*ptr = '-';
		ptr += len;
		*ptr = 0;
		while (n)
		{
			if (n > 0)
				*--ptr = n % 10 + '0';
			else
				*--ptr = -(n % -10) + '0';
			n /= 10;
		}
	}
	return (ptr);
}
