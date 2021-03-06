/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:24:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/06 18:29:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <libft_types.h>
#include <gbft.h>
#include <utils.h>
#include <libft.h>
#include <unistd.h>

static short	philo_eat(t_philo *p)
{
	pthread_mutex_lock(p->left);
	if (p->left == p->right)
	{
		philo_log(p, "has taken a fork");
		ft_usleep(philo_data()->time_die);
		pthread_mutex_unlock(p->left);
		return (1);
	}
	pthread_mutex_lock(p->right);
	ft_usleep(200);
	if (print_message(p, "has taken a fork")
		|| print_message(p, "has taken a fork")
		|| print_message(p, "is eating"))
	{
		pthread_mutex_unlock(p->left);
		pthread_mutex_unlock(p->right);
		return (1);
	}
	p->last_time_eat = get_current_time();
	ft_usleep(philo_data()->time_eat);
	pthread_mutex_unlock(p->left);
	pthread_mutex_unlock(p->right);
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
	if (is_simulation_over(p) || print_message(p, "is thinking"))
		return (1);
	return (0);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = data;
	while (philo_data()->wait)
		continue ;
	ft_usleep((philo->index - 1) * 200);
	philo->last_time_eat = get_current_time();
	while (true)
		if (philo_eat(philo) || philo_sleep(philo) || philo_think(philo))
			break ;
	pthread_mutex_lock(&philo_data()->write_mutex);
	if (!philo_data()->end_simulation
		&& philo->eat_cnt != philo_data()->needed_food)
	{
		philo_log(philo, "died");
		philo_data()->end_simulation = true;
	}
	else if (philo_data()->philo_cnt == 1)
		philo_data()->end_simulation = true;
	--philo_data()->philo_cnt;
	pthread_mutex_unlock(&philo_data()->write_mutex);
	return (NULL);
}
