/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 01:33:36 by crochu            #+#    #+#             */
/*   Updated: 2021/11/14 01:44:23 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

int invalid_arguments(const char *exec_name)
{
	write(2, "Usage: ", 7);
	ft_fprintstr(exec_name, 2);
	write(2, " number_of_philosophers time_to_die time_to_eat time_to_sleep "
	"[number_of_times_each_philosopher_must_eat]\n", 106);
	return (1);
}

int	numeric_arguments_required(void)
{
	write(2, "Numeric arguments required\n", 27);
	return (1);
}

int	out_of_memory(void)
{
	write(2, "Out of memory\n", 14);
	return (-1);
}

int	thread_error(void)
{
	write(2, "Failed to initialize a thread\n", 29);
	return (-1);
}