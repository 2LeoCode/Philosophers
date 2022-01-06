/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:59:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/06 11:42:16 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>
#include <unistd.h>
#include <philosophers.h>
#include <philo_data.h>
#include <libft.h>

unsigned long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (~0);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	ft_usleep(unsigned long us)
{
	unsigned long		cur_time;

	cur_time = get_current_time();
	us += cur_time;
	while (cur_time < us)
	{
		usleep((us - cur_time) / 2);
		cur_time = get_current_time();
	}
}

bool	is_simulation_over(t_philo *p)
{
	return (philo_data()->end_simulation
		|| get_current_time() > p->last_time_eat + philo_data()->time_die
		|| philo_data()->needed_food == p->eat_cnt);
}

void	philo_log(t_philo *p, const char *msg)
{
	ft_printul((get_current_time() - philo_data()->begin_time) / 1000);
	ft_printc(' ');
	ft_printul(p->index);
	ft_printc(' ');
	ft_println(msg);
}

int	print_message(t_philo *p, const char *msg)
{
	sem_wait(philo_data()->write_sem->ptr);
	if (is_simulation_over(p))
	{
		sem_post(philo_data()->write_sem->ptr);
		return (1);
	}
	philo_log(p, msg);
	sem_post(philo_data()->write_sem->ptr);
	return (0);
}
