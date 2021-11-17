/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_fputend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:39:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:12:06 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <unistd.h>

int	string_fputend(int fd, const t_string *s)
{
	const int	ret1 = write(fd, s->data, s->length);
	const int	ret2 = write(fd, "\n", 1);

	if (ret1 == -1 || ret2 == -1)
		return (-1);
	return (ret1 + ret2);
}
