/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:28:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:19:41 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_int.h>
#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t	total_size = nmemb * size;
	void			*ptr;

	ptr = ft_malloc(total_size);
	if (ptr)
		ft_bzero(ptr, total_size);
	return (ptr);
}
