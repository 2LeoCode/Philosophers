/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rpl_pat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:37:42 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:11:11 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

short	string_rpl_pat(t_string **s, const char *before, const char *after)
{
	const size_t	bef_len = ft_strlen(before);
	const size_t	aft_len = ft_strlen(after);
	const char		*data = (*s)->data;
	size_t			i;

	if (!bef_len || bef_len > (*s)->length)
		return (STRING_SUCCESS);
	i = ~0UL;
	while ((*s)->length - ++i >= bef_len)
	{
		if (data[i] == *before && !ft_memcmp(data + i, before, bef_len))
		{
			if (string_rpl(s, after, i, bef_len) == STRING_FAILURE)
				return (STRING_FAILURE);
			data = (*s)->data;
			i = i + aft_len - 1;
		}
	}
	return (STRING_SUCCESS);
}
