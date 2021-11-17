/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 01:34:29 by crochu            #+#    #+#             */
/*   Updated: 2021/11/17 03:28:32 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_H
# define EXCEPTIONS_H

int	invalid_arguments(const char *exec_name);
int	numeric_arguments_required(void);
int	out_of_memory(void);
int	thread_error(void);

#endif