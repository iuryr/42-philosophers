/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:36:07 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/12 17:38:27 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	print_log(t_philo *philo)
{
	int	state;

	state = get_philo_state(philo);
	pthread_mutex_lock(philo->log_mutex);
	printf("%05lu - ", philo->last_timestamp);
	printf("%d - ", philo->id);
	if (state == EATING)
		printf("is eating.\n");
	else if (state == SLEEPING)
		printf("is sleeping.\n");
	else if (state == THINKING)
		printf("is thinking.\n");
	else
		printf("is DED.\n");
	pthread_mutex_unlock(philo->log_mutex);
}
