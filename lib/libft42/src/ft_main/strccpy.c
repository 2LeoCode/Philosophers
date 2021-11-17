/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 06:01:38 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strccpy(char *dst, const char *src, int stop)
{
	ft_stpccpy(dst, src, stop);
	return (dst);
}
