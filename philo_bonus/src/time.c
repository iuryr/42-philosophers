/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:32:19 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/29 14:57:24 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

unsigned long	get_time_ms(void)
{
	unsigned long	time_ms;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_ms);
}

unsigned long	get_timestamp(t_philo *philo)
{
	unsigned long	timestamp;

	timestamp = get_time_ms() - philo->sim_start_time;
	return (timestamp);
}
