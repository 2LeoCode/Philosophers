/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printull.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:34:56 by crochu            #+#    #+#             */
/*   Updated: 2021/11/10 00:33:07 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printull(unsigned long long n)
{
	if (n < 10)
		return (ft_printc(n + '0'));
	return (ft_printull(n / 10) + ft_printull(n % 10));
}
