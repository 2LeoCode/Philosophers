/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:37:18 by crochu            #+#    #+#             */
/*   Updated: 2021/11/14 23:15:10 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <libft_types.h>

typedef struct s_philo {
	unsigned int	index;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	unsigned int	eat_cnt;
	unsigned long	last_time_eat;
}	t_philo;

int		init_forks(t_flex **forks_addr);
int		setup_threads(t_flex *forks, unsigned int cnt);
void	*philo_routine(void *data);

#endif
