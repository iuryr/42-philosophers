/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:36:07 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/24 18:01:41 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

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
		printf("%05lu %d grabbed the forks\n", philo_get_timestamp(philo),
			philo->id);
	pthread_mutex_unlock(philo->log_mutex);
}
