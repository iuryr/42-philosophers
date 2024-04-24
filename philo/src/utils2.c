/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:36:07 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/24 14:50:56 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// void	print_log(t_philo *philo)
// {
// 	int	state;
//
// 	state = get_philo_state(philo);
// 	if (read_sim_status(philo->simdata) == 1)
// 	{
// 		pthread_mutex_lock(philo->log_mutex);
// 		if (state == EATING)
// 			printf("%05lu %d is eating\n", philo->last_meal, philo->id);
// 		else if (state == SLEEPING)
// 			printf("%05lu %d is sleeping\n", philo->last_sleep, philo->id);
// 		else
// 			printf("%05lu %d is thinking\n", philo->last_think, philo->id);
// 		pthread_mutex_unlock(philo->log_mutex);
// 	}
// }

void	print_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->log_mutex);
	printf("%05lu %d is eating\n", philo->last_meal, philo->id);
	pthread_mutex_unlock(philo->log_mutex);
}

void	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->log_mutex);
	printf("%05lu %d is sleeping\n", philo->last_sleep, philo->id);
	pthread_mutex_unlock(philo->log_mutex);
}

void	print_think(t_philo *philo)
{
	pthread_mutex_lock(philo->log_mutex);
	printf("%05lu %d is thinking\n", philo->last_think, philo->id);
	pthread_mutex_unlock(philo->log_mutex);
}

void	print_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->log_mutex);
	printf("%05lu %d died\n", philo->time_of_death, philo->id);
	pthread_mutex_unlock(philo->log_mutex);
}

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->log_mutex);
	if (read_sim_status(philo->simdata) == 1)
		printf("%05lu %d grabbed the forks\n", philo_get_timestamp(philo), philo->id);
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
	if (simdata->go_on == 1)
		simdata->go_on = 0;
	else
		simdata->go_on = 1;
	pthread_mutex_unlock(&(simdata->sim_mutex));
}

unsigned int	read_stuffed_philos(t_simdata *simdata)
{
	unsigned int	stuffed_philos;

	pthread_mutex_lock(&(simdata->stuffed_mutex));
	stuffed_philos = simdata->stuffed_philos;
	pthread_mutex_unlock(&(simdata->stuffed_mutex));
	return (stuffed_philos);
}

void	update_stuffed_philos(t_simdata *simdata)
{
	pthread_mutex_lock(&(simdata->stuffed_mutex));
	simdata->stuffed_philos++;
	pthread_mutex_unlock(&(simdata->stuffed_mutex));
}
