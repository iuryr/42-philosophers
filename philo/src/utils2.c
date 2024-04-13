/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:36:07 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/13 14:30:16 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	print_log(t_philo *philo)
{
	int	state;

	state = get_philo_state(philo);
	pthread_mutex_lock(philo->log_mutex);
	if (state == EATING)
		printf("%05lu - %d - is eating.\n", philo->last_meal, philo->id);
	else if (state == SLEEPING)
		printf("%05lu - %d - is sleeping.\n", philo->last_sleep, philo->id);
	else if (state == THINKING)
		printf("%05lu - %d - is thinking.\n", philo->last_think, philo->id);
	else
		printf("%05lu - %d - is DED.\n", philo->time_of_death, philo->id);
	pthread_mutex_unlock(philo->log_mutex);
}

int	read_sim_status(t_simdata *simdata)
{
	pthread_mutex_lock(&(simdata->sim_mutex));
	if (simdata->go_on == 1)
	{
		pthread_mutex_unlock(&(simdata->sim_mutex));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(simdata->sim_mutex));
		return (0);
	}
}

void	change_sim_status(t_simdata *simdata)
{
	pthread_mutex_lock(&(simdata->sim_mutex));
	simdata->go_on = 0;
	pthread_mutex_unlock(&(simdata->sim_mutex));
}
