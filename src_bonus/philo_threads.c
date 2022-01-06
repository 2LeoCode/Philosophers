/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:24:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/06 18:38:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <libft_types.h>
#include <gbft.h>
#include <utils.h>
#include <libft.h>
#include <unistd.h>

static short	philo_die(int sem_cnt) {
	while (sem_cnt--)
		sem_post(philo_data()->forks->ptr);
	return (1);
}

static short	philo_eat(t_philo *p)
{
	sem_wait(philo_data()->forks->ptr);
	ft_usleep(200);
	if (print_message(p, "has taken a fork"))
		return (philo_die(1));
	if (philo_data()->philo_cnt == 1)
	{
		ft_usleep(philo_data()->time_die);
		return (philo_die(1));
	}
	sem_wait(philo_data()->forks->ptr);
	if (print_message(p, "has taken a fork") || print_message(p, "is eating"))
		return (philo_die(2));
	p->last_time_eat = get_current_time();
	ft_usleep(philo_data()->time_eat);
	sem_post(philo_data()->forks->ptr);
	sem_post(philo_data()->forks->ptr);
	++p->eat_cnt;
	return (0);
}

static short	philo_sleep(t_philo *p)
{
	if (print_message(p, "is sleeping"))
		return (1);
	ft_usleep(philo_data()->time_sleep);
	return (0);
}

static short	philo_think(t_philo *p)
{
	if (print_message(p, "is thinking") || is_simulation_over(p))
		return (1);
	return (0);
}

void	*philo_routine(void *data)
{
	t_philo			*philo;

	philo = data;
	while (philo_data()->wait)
		continue ;
	if (philo->index % 2)
		ft_usleep(500);
	philo->last_time_eat = get_current_time();
	while (true)
		if (philo_eat(philo) || philo_sleep(philo) || philo_think(philo))
			break ;
	sem_wait(philo_data()->write_sem->ptr);
	if (!philo_data()->end_simulation
		&& philo->eat_cnt != philo_data()->needed_food)
	{
		philo_log(philo, "died");
		philo_data()->end_simulation = true;
	}
	else if (philo_data()->philo_cnt == 1)
		philo_data()->end_simulation = true;
	--philo_data()->philo_cnt;
	sem_post(philo_data()->write_sem->ptr);
	return (NULL);
}
