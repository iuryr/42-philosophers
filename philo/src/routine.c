/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/11 15:39:16 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	//delete counter later
	while (42)
	{
		if (philo->state == DED)
			break;
		eat(philo);
		if (philo->state == DED)
			break;
		philo_sleep(philo);
		if (philo->state == DED)
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
	philo->last_timestamp = get_timestamp(philo);
	philo->last_meal = philo->last_timestamp;
	print_log(philo);
	while ((get_timestamp(philo) - philo->last_timestamp < philo->tt_eat)
		&& philo->state != DED);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->state == DED)
		return ;
	change_state('S', philo);
	philo->last_timestamp = get_timestamp(philo);
	print_log(philo);
	while ((get_timestamp(philo) - philo->last_timestamp < philo->tt_sleep)
		&& philo->state != DED);
}

void	think(t_philo *philo)
{
	if (philo->state == DED)
		return ;
	change_state('T', philo);
	philo->last_timestamp = get_timestamp(philo);
	print_log(philo);
}

//Thinking, Sleeping, Eating, D
void	change_state(char c, t_philo *philo)
{
	pthread_mutex_lock(&(philo->state_mutex));
	if (c == 'S')
		philo->state = SLEEPING;
	else if (c == 'E')
		philo->state = EATING;
	else if (c == 'T')
		philo->state = THINKING;
	else
		philo->state = DED;
	pthread_mutex_unlock(&(philo->state_mutex));
}
