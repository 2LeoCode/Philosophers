/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:01:36 by crochu            #+#    #+#             */
/*   Updated: 2021/11/14 01:45:29 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define TIME_ERROR ~0UL

# include "philosophers.h"

unsigned long	get_current_time(void);
void			ft_usleep(unsigned long us);
int				print_message(t_philo *p, const char *msg);
bool			is_simulation_over(t_philo *p);

#endif
