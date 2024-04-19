/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/19 18:47:55 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
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
	if (grab_forks(philo) != 0)
	{
		while (get_philo_state(philo) != DED);
		return ;
	}
	print_fork(philo);
	change_state('E', philo);
	print_log(philo);
	usleep(philo->simdata->tt_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	philo->n_dinners++;
}

int	grab_forks(t_philo *philo)
{
	int ret;

	if (philo->id % 2 == 0)
		ret = grab_forks_even(philo);
	else
		ret = grab_forks_odd(philo);
	return (ret);
}

int	grab_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (read_sim_status(philo->simdata) == 0)
	{
		pthread_mutex_unlock(philo->left);
		return (1);
	}
	pthread_mutex_lock(philo->right);
	return (0);
};

int	grab_forks_odd(t_philo *philo)
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
	return (0);
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
