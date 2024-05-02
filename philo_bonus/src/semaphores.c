/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:59:27 by iusantos          #+#    #+#             */
/*   Updated: 2024/05/02 15:24:52 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

void	unlink_semaphores(void)
{
	sem_unlink("/simulation_sem");
	sem_unlink("/print_sem");
	sem_unlink("/forks_sem");
}

void	close_semaphores(t_semaphore_set *semaphore_set)
{
	sem_close(semaphore_set->simulation_sem);
	sem_close(semaphore_set->print_sem);
	sem_close(semaphore_set->forks_sem);
}

void	prepare_semaphores(t_semaphore_set *semaphore_set, char **argv)
{
	semaphore_set->simulation_sem = sem_open("/simulation_sem", O_CREAT,
			0666, 0);
	semaphore_set->print_sem = sem_open("/print_sem", O_CREAT,
			0666, 1);
	semaphore_set->forks_sem = sem_open("/forks_sem", O_CREAT,
			0666, philo_atouint(argv[1]));
}
