/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kek.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:14:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:15:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_kek(void)
{
	write(1, "kek\n", 4);
}
