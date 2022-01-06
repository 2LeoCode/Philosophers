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

static int	init_philo(pthread_mutex_t *left, pthread_mutex_t *right)
{
	static unsigned int	philo_index;
	t_philo				*new_philo;

	if (gb_alloc(&new_philo, sizeof(t_philo)))
		return (-1);
	new_philo->index = ++philo_index;
	new_philo->last_time_eat = 0;
	new_philo->eat_cnt = 0;
	new_philo->left = left;
	new_philo->right = right;
	if (pthread_create(&new_philo->thread, NULL, philo_routine, new_philo))
		return (-1);
	pthread_detach(new_philo->thread);
	return (0);
}

int	init_forks(t_flex **forks_addr)
{
	unsigned int	i;

	if (gb_alloc_flex(forks_addr,
			philo_data()->philo_cnt * sizeof(pthread_mutex_t)))
		return (-1);
	i = ~0;
	while (++i < philo_data()->philo_cnt)
	{
		pthread_mutex_init((pthread_mutex_t *)(*forks_addr)->data + i, NULL);
		if (gb_push((pthread_mutex_t *)(*forks_addr)->data + i,
			(t_freef *)pthread_mutex_destroy))
			return (-1);
	}
	return (0);
}

int	setup_threads(t_flex *forks, unsigned int cnt)
{
	unsigned int	i;

	i = ~0;
	while (++i < cnt)
	{
		if (init_philo((pthread_mutex_t *)forks->data + i,
				(pthread_mutex_t *)forks->data + (i + 1) % cnt))
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
