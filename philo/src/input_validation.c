/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:39:49 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/12 15:24:51 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	set_meta(t_meta *meta, int argc, char **argv)
{
	meta->error_msg = NULL;
	meta->n_philos = philo_atouint(argv[1]);
	meta->data.tt_death = philo_atouint(argv[2]);
	meta->data.tt_eat = philo_atouint(argv[3]);
	meta->data.tt_sleep = philo_atouint(argv[4]);
	meta->data.go_on = 1;
	pthread_mutex_init(&(meta->log_mutex), NULL);
	if (argc == 6)
	{
		meta->opt_param_set = 1;
		meta->data.max_dinners = philo_atouint(argv[5]);
	}
	else
		meta->opt_param_set = 0;
}

int	validate_inputs(t_meta *meta)
{
	if (meta->n_philos == 0)
	{
		meta->error_msg = "Number of philosophers must be a positive integer\n";
		return (1);
	}
	if (meta->data.tt_death == 0 || meta->data.tt_eat == 0
			| meta->data.tt_sleep == 0)
	{
		meta->error_msg = "Time to (die|eat|sleep) must be positive integers\n";
		return (1);
	}
	if (meta->opt_param_set == 0)
		return (0);
	if (meta->opt_param_set == 1 && meta->data.max_dinners == 0)
	{
		meta->error_msg = "Max number of dinners must be a positive integer\n";
		return (1);
	}
	return (0);
}
