/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:38:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/05 13:26:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <philo_data.h>
#include <unistd.h>
#include <libft.h>
#include <gbft.h>
#include <exceptions.h>

static int	philo_error(int (*errfun)(), void *param)
{
	gb_clear();
	if (param)
		return (errfun(param));
	return (errfun());
}

int	main(int argc, char **argv)
{
	int				pdata_ret;
	t_flex			*forks;

	if (argc != 5 && argc != 6)
		return (philo_error(invalid_arguments, argv[0]));
	pdata_ret = init_philo_data(argc - 1, argv + 1);
	if (pdata_ret == 1)
		return (philo_error(numeric_arguments_required, NULL));
	if (pdata_ret == -1)
		return (philo_error(out_of_memory, NULL));
	if (philo_data()->philo_cnt && philo_data()->needed_food)
	{
		if (init_forks(&forks))
			return (philo_error(out_of_memory, NULL));
		if (setup_threads(forks, philo_data()->philo_cnt))
			return (philo_error(thread_error, NULL));
		while (!philo_data()->end_simulation || philo_data()->philo_cnt)
			usleep(0x42BB);
	}
	gb_clear();
	return (0);
}
