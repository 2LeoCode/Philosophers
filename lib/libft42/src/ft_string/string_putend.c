/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_putend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:37:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:12:13 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <unistd.h>

int	string_putend(const t_string *s)
{
	const int	ret1 = write(1, s->data, s->length);
	const int	ret2 = write(1, "\n", 1);

	if (ret1 == -1 || ret2 == -1)
		return (-1);
	return (ret1 + ret2);
}
