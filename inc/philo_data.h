/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:44:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/05 13:26:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DATA_H
# define PHILO_DATA_H

# include <pthread.h>
# include <stdbool.h>

# define NO_EAT_CNT ~0UL

typedef struct s_philo_data {
	unsigned long	philo_cnt;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	needed_food;
	pthread_mutex_t	write_mutex;
	unsigned long	begin_time;
	volatile bool	wait;
	volatile bool	end_simulation;
}	t_philo_data;

int				init_philo_data(int cnt, char **data);
t_philo_data	*philo_data(void);

#endif
