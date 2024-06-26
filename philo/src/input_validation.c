/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:39:49 by iusantos          #+#    #+#             */
/*   Updated: 2024/05/02 14:55:22 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static void	init_forks_mutexes(t_meta *meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta->n_philos)
	{
		pthread_mutex_init(&(meta->simdata.forks[i]), NULL);
		i++;
	}
}

void	set_meta(t_meta *meta, int argc, char **argv)
{
	meta->error_msg = NULL;
	meta->n_philos = philo_atouint(argv[1]);
	meta->simdata.n_philos = meta->n_philos;
	meta->simdata.tt_death = philo_atouint(argv[2]);
	meta->simdata.tt_eat = philo_atouint(argv[3]);
	meta->simdata.tt_sleep = philo_atouint(argv[4]);
	meta->opt_param_set = 0;
	meta->simdata.stuffed_philos = 0;
	meta->simdata.go_on = 0;
	meta->simdata.forks = malloc(meta->n_philos * sizeof(pthread_mutex_t));
	init_forks_mutexes(meta);
	pthread_mutex_init(&(meta->log_mutex), NULL);
	pthread_mutex_init(&(meta->simdata.sim_mutex), NULL);
	pthread_mutex_init(&(meta->simdata.stuffed_mutex), NULL);
	if (argc == 6)
	{
		meta->opt_param_set = 1;
		meta->simdata.max_dinners = philo_atouint(argv[5]);
	}
	else
		meta->simdata.max_dinners = 0;
}

int	validate_inputs(t_meta *meta)
{
	if (meta->n_philos == 0)
	{
		meta->error_msg = "Number of philosophers must be a positive integer\n";
		return (1);
	}
	if (meta->simdata.tt_death == 0 || meta->simdata.tt_eat == 0
		| meta->simdata.tt_sleep == 0)
	{
		meta->error_msg = "Time to (die|eat|sleep) must be positive integers\n";
		return (1);
	}
	if (meta->opt_param_set == 1 && meta->simdata.max_dinners <= 0)
	{
		meta->error_msg = "Max number of dinners must be a positive integer\n";
		return (1);
	}
	return (0);
}
