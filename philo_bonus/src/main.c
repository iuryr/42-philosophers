/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:52:53 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/29 12:16:09 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

void	routine(t_philo *philo, t_semaphore_set *semaphore_set)
{
	while (*(int *) semaphore_set->simulation_sem == 0)
		;
	printf("Philo %d criado.\n", philo->id);
	sem_close(semaphore_set->simulation_sem);
	exit(EXIT_SUCCESS);
};

int	main(int argc, char **argv)
{
	t_philo			philo;
	t_semaphore_set	semaphore_set;
	pid_t			child_pid;
	unsigned int	i;

	sem_unlink("/simulation_sem");
	sem_unlink("/print_sem");
	validate_inputs(argc, argv);
	prepare_semaphores(&semaphore_set);
	prepare_philo(&philo, argc, argv);
	i = 1;
	while (i <= philo_atouint(argv[1]))
	{
		philo.id = i;
		child_pid = safe_fork();
		if (child_pid == 0)
			routine(&philo, &semaphore_set);
		i++;
	}
	sleep(2);
	sem_post(semaphore_set.simulation_sem);
	sleep(2);
	sem_close(semaphore_set.simulation_sem);
	sem_unlink("/simulation_sem");
	sem_unlink("/print_sem");
	return (EXIT_SUCCESS);
}

