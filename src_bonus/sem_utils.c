/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:54:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/05 13:26:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>
#include <fcntl.h>
#include <gbft.h>
#include <sys/stat.h>

t_sem	*sem_new(const char *name, int oflag, int mode, int value)
{
	t_sem	*ptr;

	sem_unlink(name);
	ptr = ft_malloc(sizeof(t_sem));
	if (ptr)
	{
		ptr->name = ft_strdup(name);
		ptr->ptr = sem_open(name, oflag, mode, value);
		if (!ptr->name || !ptr->ptr)
		{
			ft_free(ptr->name);
			ft_free(ptr);
			ptr = NULL;
		}
	}
	return (ptr);
}

void	sem_kill(t_sem *sem)
{
	sem_close(sem->ptr);
	sem_unlink(sem->name);
	ft_free(sem->name);
	ft_free(sem);
}
