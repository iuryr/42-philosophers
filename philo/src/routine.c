/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/13 15:13:37 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (42 && read_sim_status(philo->simdata))
	{
		// if (philo->n_dinners == philo->simdata->max_dinners)
		// 	change_state('D', philo);
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	if (get_philo_state(philo) == DED || read_sim_status(philo->simdata) == 0)
		return ;
	//essa mundança de estado abaixo só acontece caso ele consiga comer.
	change_state('E', philo);
	print_log(philo);
	usleep(philo->simdata->tt_eat * 1000);
	philo->n_dinners++;
}

void	philo_sleep(t_philo *philo)
{
	if (get_philo_state(philo) == DED || read_sim_status(philo->simdata) == 0)
		return ;
	change_state('S', philo);
	print_log(philo);
	usleep(philo->simdata->tt_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (get_philo_state(philo) == DED || read_sim_status(philo->simdata) == 0)
		return ;
	change_state('T', philo);
	print_log(philo);
}

void	change_state(char c, t_philo *philo)
{
	pthread_mutex_lock(&(philo->state_mutex));
	if (c == 'S' && philo->state != DED)
	{
		philo->state = SLEEPING;
		philo->last_sleep = philo_get_timestamp(philo);
	}
	else if (c == 'E' && philo->state != DED)
	{
		philo->state = EATING;
		philo->last_meal = philo_get_timestamp(philo);
	}
	else if (c == 'T' && philo->state != DED)
	{
		philo->state = THINKING;
		philo->last_think = philo_get_timestamp(philo);
	}
	else if (philo->state != DED)
	{
		philo->state = DED;
		philo->time_of_death = philo_get_timestamp(philo);
	}
	pthread_mutex_unlock(&(philo->state_mutex));
}
