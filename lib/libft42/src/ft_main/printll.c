/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:32:53 by crochu            #+#    #+#             */
/*   Updated: 2021/11/10 00:32:58 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printll(long long n)
{
	if (n < 0)
		return (ft_printc('-') + ft_printll(ft_abs(n / 10))
			+ ft_printll(ft_abs(n % 10)));
	else if (n < 10)
		return (ft_printc(n + '0'));
	return (ft_printll(n / 10) + ft_printll(n % 10));
}
