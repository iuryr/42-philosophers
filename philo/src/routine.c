/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/10 15:22:42 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	//delete counter later
	int i = 0;
	while (i++ < 3)
	{
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return NULL;
}

void	eat(t_philo *philo)
{
	philo->state = EATING;
	philo->last_timestamp = get_timestamp(philo);
	print_log(philo);
	while (get_timestamp(philo) - philo->last_timestamp < philo->tt_eat);
	philo->last_meal = philo->last_timestamp;
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	philo->last_timestamp = get_timestamp(philo);
	print_log(philo);
	while (get_timestamp(philo) - philo->last_timestamp < philo->tt_eat);
}

void	think(t_philo *philo)
{
	philo->state = THINKING;
	philo->last_timestamp = get_timestamp(philo);
	print_log(philo);
	while (get_timestamp(philo) - philo->last_timestamp < philo->tt_eat);
}
