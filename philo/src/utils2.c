/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:36:07 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/10 14:50:54 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	print_log(t_philo *philo)
{
	pthread_mutex_lock(philo->log_mutex);
	printf("%lu - ", philo->last_timestamp);
	printf("%d - ", philo->id);
	if (philo->state == EATING)
		printf("is eating.\n");
	else if (philo->state == SLEEPING)
		printf("is sleeping.\n");
	else if (philo->state == THINKING)
		printf("is thinking.\n");
	else
		printf("is DED.\n");
	pthread_mutex_unlock(philo->log_mutex);
}
