/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   println.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:13:40 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 17:14:17 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_println(const char *s)
{
	return (ft_fprintln(s, 1));
}
