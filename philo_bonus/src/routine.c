/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:53:08 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/29 16:20:15 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

static int	grab_forks(t_philo	*philo, t_semaphore_set *semaphore_set)
{
	while (*(int *) semaphore_set->forks_sem < 2)
		;
	sem_wait(semaphore_set->forks_sem);
	sem_wait(semaphore_set->forks_sem);
	philo->last_grab = get_timestamp(philo);
	print_log('F', philo, semaphore_set); 
	return (0);
}

static int	eat(t_philo	*philo, t_semaphore_set *semaphore_set)
{
	philo->last_meal = get_timestamp(philo);
	print_log('E', philo, semaphore_set);
	usleep(philo->tt_eat * 1000);
	sem_post(semaphore_set->forks_sem);
	sem_post(semaphore_set->forks_sem);
	return (0);
}

static int	philo_sleep(t_philo	*philo, t_semaphore_set *semaphore_set)
{
	philo->last_sleep = get_timestamp(philo);
	print_log('S', philo, semaphore_set);
	usleep(philo->tt_sleep * 1000);
	return (0);
}

static int	think(t_philo	*philo, t_semaphore_set *semaphore_set)
{
	philo->last_think = get_timestamp(philo);
	print_log('T', philo, semaphore_set);
	return (0);
}

void	routine(t_philo *philo, t_semaphore_set *semaphore_set)
{
	while (*(int *) semaphore_set->simulation_sem == 0)
		;
	grab_forks(philo, semaphore_set);
	eat(philo, semaphore_set);
	philo_sleep(philo, semaphore_set);
	think(philo, semaphore_set);
	sem_close(semaphore_set->simulation_sem);
	exit(EXIT_SUCCESS);
}

