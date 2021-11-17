/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:44:00 by crochu            #+#    #+#             */
/*   Updated: 2021/11/16 03:41:33 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DATA_H
# define PHILO_DATA_H

# include <pthread.h>
# include <stdbool.h>
# include <semaphore.h>
# include <libft_types.h>
# include "utils.h"

# define NO_EAT_CNT ~0UL

typedef struct s_philo_data {
	unsigned long	philo_cnt;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	needed_food;
	t_sem			*write_sem;
	unsigned long	begin_time;
	volatile bool	wait;
	volatile bool	end_simulation;
	t_sem			*forks;
}	t_philo_data;

int				init_philo_data(int cnt, char **data);
t_philo_data	*philo_data(void);

#endif
