/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintln.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:11:18 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 17:13:32 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_fprintln(const char *s, int fd)
{
	int	ret;

	ret = ft_fprintstr(s, fd) + 1;
	if (!ret || ft_fprintc('\n', fd) == -1)
		return (-1);
	return (ret);
}
