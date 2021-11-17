/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:11:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:25:17 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static size_t	ft_splitsize(const char *s, int c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = ~0UL;
	while (s[++i])
	{
		++size;
		while (s[i] && s[i] == c)
			++i;
	}
	return (size);
}

static void	next_token(const char **s, char c)
{
	while (**s && **s != c)
		++*s;
	while (**s && **s == c)
		++*s;
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	i;

	while (*s == c)
		++s;
	ptr = ft_malloc(sizeof(char *) * (ft_splitsize(s, c) + 1));
	if (ptr)
	{
		i = ~0UL;
		while (*s)
		{
			ptr[i + 1] = ft_strcdup(s, c);
			next_token(&s, c);
			if (ptr[++i])
				continue ;
			while (i--)
				ft_free(ptr[i]);
			ft_free(ptr);
			ptr = NULL;
			break ;
		}
		ptr[++i] = NULL;
	}
	return (ptr);
}
