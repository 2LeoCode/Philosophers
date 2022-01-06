/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 01:36:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/05 13:26:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <libft.h>
#include <gbft.h>
#include <utils.h>
#include <fcntl.h>
#include <sys/stat.h>

static int	init_philo(void)
{
	static unsigned int	philo_index;
	t_philo				*new_philo;

	if (gb_alloc(&new_philo, sizeof(t_philo)))
		return (-1);
	new_philo->index = ++philo_index;
	new_philo->last_time_eat = 0;
	new_philo->eat_cnt = 0;
	if (pthread_create(&new_philo->thread, NULL, philo_routine, new_philo))
		return (-1);
	pthread_detach(new_philo->thread);
	return (0);
}

int	init_forks(void)
{
	t_philo_data *const	pdata = philo_data();

	sem_unlink("/PHILO_FORKS");
	pdata->forks = sem_new("/PHILO_FORKS", O_CREAT | O_EXCL, S_IRWXU,
			philo_data()->philo_cnt);
	if (!philo_data()->forks || gb_push(philo_data()->forks, sem_kill))
		return (-1);
	return (0);
}

int	setup_threads(unsigned int cnt)
{
	unsigned int	i;

	i = ~0;
	while (++i < cnt)
	{
		if (init_philo())
		{
			philo_data()->wait = false;
			philo_data()->end_simulation = true;
			return (-1);
		}
	}
	philo_data()->begin_time = get_current_time();
	philo_data()->wait = false;
	return (0);
}
