/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:17:41 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/29 17:29:28 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

void	safe_print(char c, t_philo *philo, t_semaphore_set *semaphore_set)
{
	sem_wait(semaphore_set->print_sem);
	if (c == 'E')
		printf("%05lu %d is eating\n", philo->last_meal, philo->id);
	else if (c == 'S')
		printf("%05lu %d is sleeping\n", philo->last_sleep, philo->id);
	else if (c == 'T')
		printf("%05lu %d is thinking\n", philo->last_think, philo->id);
	else if (c == 'F')
		printf("%05lu %d grabbed forks\n", philo->last_grab, philo->id);
	else if (c == 'D')
		printf("%05lu %d died\n", philo->time_of_death, philo->id);
	sem_post(semaphore_set->print_sem);
}

int	print_log(char c, t_philo *philo, t_semaphore_set *semaphore_set)
{
	if (c == 'E')
		safe_print(c, philo, semaphore_set);
	else if (c == 'S')
		safe_print(c, philo, semaphore_set);
	else if (c == 'T')
		safe_print(c, philo, semaphore_set);
	else if (c == 'F')
		safe_print(c, philo, semaphore_set);
	else if (c == 'D')
		safe_print(c, philo, semaphore_set);
	else
		return (1);
	return (0);
}
