/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:09:13 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/24 18:10:57 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	think(t_philo *philo)
{
	if (get_philo_state(philo) == DED || read_sim_status(philo->simdata) == 0)
		return ;
	change_state('T', philo);
}

void	change_state(char c, t_philo *philo)
{
	pthread_mutex_lock(&(philo->state_mutex));
	if (c == 'S' && philo->state != DED)
	{
		philo->state = SLEEPING;
		philo->last_sleep = philo_get_timestamp(philo);
		print_sleep(philo);
	}
	else if (c == 'E' && philo->state != DED)
	{
		philo->state = EATING;
		philo->last_meal = philo_get_timestamp(philo);
		print_eat(philo);
	}
	else if (c == 'T' && philo->state != DED)
	{
		philo->state = THINKING;
		philo->last_think = philo_get_timestamp(philo);
		print_think(philo);
	}
	else if (philo->state != DED)
	{
		philo->state = DED;
		philo->time_of_death = philo_get_timestamp(philo);
	}
	pthread_mutex_unlock(&(philo->state_mutex));
}
