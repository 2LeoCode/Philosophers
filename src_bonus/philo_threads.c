/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:24:45 by crochu            #+#    #+#             */
/*   Updated: 2021/11/17 14:07:31 by crochu           ###   ########.fr       */
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
	sem_wait(philo_data()->forks->ptr);
	ft_usleep(200);
	if (print_message(p, "has taken a fork"))
	{
		sem_post(philo_data()->forks->ptr);
		return (-1);
	}
	sem_wait(philo_data()->forks->ptr);
	if (print_message(p, "has taken a fork") || print_message(p, "is eating"))
	{
		sem_post(philo_data()->forks->ptr);
		sem_post(philo_data()->forks->ptr);
		return (1);
	}
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
	if (is_simulation_over(p) || print_message(p, "is thinking"))
		return (1);
	if (is_simulation_over(p))
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
		ft_printul((get_current_time() - philo_data()->begin_time) / 1000);
		ft_printc(' ');
		ft_printul(philo->index);
		ft_println(" died");
		philo_data()->end_simulation = true;
	}
	else if (philo_data()->philo_cnt == 1)
		philo_data()->end_simulation = true;
	--philo_data()->philo_cnt;
	sem_post(philo_data()->write_sem->ptr);
	return (NULL);
}
