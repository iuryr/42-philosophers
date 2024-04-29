/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:52:53 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/29 18:50:38 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_philo			philo;
	t_semaphore_set	semaphore_set;
	pid_t			child_pid;
	unsigned int	i;

	unlink_semaphores();
	validate_inputs(argc, argv);
	prepare_semaphores(&semaphore_set, argv);
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
	sem_post(semaphore_set.simulation_sem);
	waitpid(-1, NULL, 0);
	kill(0, SIGKILL);
	sem_close(semaphore_set.simulation_sem);
	unlink_semaphores();
	return (EXIT_SUCCESS);
}

