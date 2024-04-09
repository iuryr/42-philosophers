/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:36:07 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/09 18:08:28 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

unsigned long	get_timestamp(t_philo *philo)
{
	unsigned long	timestamp;

	timestamp = get_time_ms() - philo->sim_start_time;
	return (timestamp);
}

void	print_log(t_philo *philo)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	printf("%lu - ", get_timestamp(philo));
	printf("%d - ", philo->id);
	if (philo->state == EATING)
		printf("is eating.\n");
	else if (philo->state == SLEEPING)
		printf("is sleeping.\n");
	else if (philo->state == THINKING)
		printf("is thinking.\n");
	else
		printf("is DED.\n");
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
}
