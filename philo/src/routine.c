/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/24 14:50:56 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (read_sim_status(philo->simdata) != 1);
	while (42 && read_sim_status(philo->simdata))
	{
		eat(philo);
		philo_sleep(philo);
		think(philo);
		if (philo->n_dinners == philo->simdata->max_dinners)
		{
			update_stuffed_philos(philo->simdata);
			change_state('D', philo);
			return (NULL);
		}
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	if (get_philo_state(philo) == DED || read_sim_status(philo->simdata) == 0)
		return ;
	if (philo->id % 2 == 0)
		eat_even(philo);
	else
		eat_odd(philo);
	philo->n_dinners++;
}

int	eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (read_sim_status(philo->simdata) == 0)
	{
		pthread_mutex_unlock(philo->left);
		return (1);
	}
	pthread_mutex_lock(philo->right);
	if (read_sim_status(philo->simdata) != 0)
	{
		print_fork(philo);
		change_state('E', philo);
		usleep(philo->simdata->tt_eat * 1000);
	}
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (0);
}

int	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	if (read_sim_status(philo->simdata) == 0)
	{
		pthread_mutex_unlock(philo->right);
		return (1);
	}
	if (philo->left != NULL)
		pthread_mutex_lock(philo->left);
	else
	{
		pthread_mutex_unlock(philo->right);
		return (1);
	}
	if (read_sim_status(philo->simdata) != 0)
	{
		print_fork(philo);
		change_state('E', philo);
		usleep(philo->simdata->tt_eat * 1000);
	}
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	return (0);
}


void	philo_sleep(t_philo *philo)
{
	if (get_philo_state(philo) == DED || read_sim_status(philo->simdata) == 0)
		return ;
	change_state('S', philo);
	usleep(philo->simdata->tt_sleep * 1000);
}

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
