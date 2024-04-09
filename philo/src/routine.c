/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/09 18:14:29 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	print_log(philo);
	while (42)
		eat(philo);
	// printf("%lu - Philo %d: current timestamp\n", get_timestamp(philo), philo->id); 
	return NULL;
}

void	eat(t_philo *philo)
{
	philo->state = EATING;
	print_log(philo);
	if (philo->last_meal == 0)
	{
		philo->last_meal = get_timestamp(philo);
		while (get_time_ms() - philo->sim_start_time < philo->tt_eat);
	}
	else
		while (get_time_ms() - philo->last_meal < philo->tt_eat);
}
