/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:35:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/05 13:26:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <libft.h>
#include <gbft.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

t_philo_data	*philo_data(void)
{	
	static t_philo_data	philo_data;

	return (&philo_data);
}

bool	args_not_digit(int cnt, char **args)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cnt)
	{
		j = -1;
		while (args[i][++j])
			if (!ft_isdigit(args[i][j]))
				return (true);
	}
	return (false);
}

int	init_philo_data(int cnt, char **data)
{
	t_philo_data *const	pdata = philo_data();

	pdata->wait = true;
	pdata->end_simulation = false;
	if (args_not_digit(cnt, data))
		return (1);
	pdata->philo_cnt = ft_strtoul(data[0], NULL, 0);
	pdata->time_die = ft_strtoul(data[1], NULL, 0);
	pdata->time_eat = ft_strtoul(data[2], NULL, 0);
	pdata->time_sleep = ft_strtoul(data[3], NULL, 0);
	if (cnt == 5)
		pdata->needed_food = ft_strtoul(data[4], NULL, 0);
	else
		pdata->needed_food = NO_EAT_CNT;
	if (errno == ERANGE || (~0UL / 1000 < pdata->time_die)
		|| (~0UL / 1000 < pdata->time_eat)
		|| (~0UL / 1000 < pdata->time_sleep))
		return (1);
	pdata->time_die *= 1000;
	pdata->time_eat *= 1000;
	pdata->time_sleep *= 1000;
	pdata->write_sem = sem_new("/PHILO_WRITE", O_CREAT | O_EXCL, S_IRWXU, 1);
	if (!pdata->write_sem || gb_push(pdata->write_sem, sem_kill))
		return (-1);
	return (0);
}
