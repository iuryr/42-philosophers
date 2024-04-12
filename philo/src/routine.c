/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/12 17:25:48 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (42 && philo->simdata->go_on)
	{
		// if (philo->n_dinners == philo->simdata->max_dinners)
		// 	change_state('D', philo);
		if (philo->state == DED || philo->simdata->go_on == 0)
			break;
		eat(philo);
		if (philo->state == DED || philo->simdata->go_on == 0)
			break;
		philo_sleep(philo);
		if (philo->state == DED || philo->simdata->go_on == 0)
			break;
		think(philo);
	}
	return NULL;
}

void	eat(t_philo *philo)
{
	if (philo->state == DED)
		return ;
	//essa mundança de estado abaixo só acontece caso ele consiga comer.
	change_state('E', philo);
	print_log(philo);
	usleep(philo->simdata->tt_eat * 1000);
	// while ((get_timestamp(philo) - philo->last_timestamp < philo->tt_eat)
	// 	&& philo->state != DED);
	philo->n_dinners++;
}

void	philo_sleep(t_philo *philo)
{
	if (philo->state == DED)
		return ;
	change_state('S', philo);
	print_log(philo);
	// while ((get_timestamp(philo) - philo->last_timestamp < philo->tt_sleep)
	// 	&& philo->state != DED);
	usleep(philo->simdata->tt_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (philo->state == DED)
		return ;
	change_state('T', philo);
	print_log(philo);
}

void	change_state(char c, t_philo *philo)
{
	pthread_mutex_lock(&(philo->state_mutex));
	philo->last_timestamp = philo_get_timestamp(philo);
	if (c == 'S')
		philo->state = SLEEPING;
	else if (c == 'E')
	{
		philo->state = EATING;
		philo->last_meal = philo->last_timestamp;
	}
	else if (c == 'T')
		philo->state = THINKING;
	else
		philo->state = DED;
	pthread_mutex_unlock(&(philo->state_mutex));
}
