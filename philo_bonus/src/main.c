/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:52:53 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/30 17:21:09 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

void	kill_children(t_child_info child_info)
{
	int	i;

	i = 0;
	while (i < 201)
	{
		kill(child_info.child[i], SIGKILL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo			philo;
	t_semaphore_set	semaphore_set;
	t_child_info	child_info;
	unsigned int	i;

	unlink_semaphores();
	validate_inputs(argc, argv);
	prepare_semaphores(&semaphore_set, argv);
	prepare_philo(&philo, argc, argv);
	i = 1;
	while (i <= philo_atouint(argv[1]))
	{
		philo.id = i;
		child_info.child[i-1] = safe_fork();
		if (child_info.child[i-1] == 0)
			routine(&philo, &semaphore_set);
		i++;
	}
	sem_post(semaphore_set.simulation_sem);
	while (waitpid(-1, &(child_info.exit_status), 0) != -1)
	{
		if (WEXITSTATUS(child_info.exit_status) == DED)
			kill_children(child_info);
	}
	//sub por close_semaphores
	sem_close(semaphore_set.simulation_sem);
	unlink_semaphores();
	return (EXIT_SUCCESS);
}

