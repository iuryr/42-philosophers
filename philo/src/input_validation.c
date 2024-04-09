/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:39:49 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/09 17:13:14 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	set_meta(t_meta *meta, int argc, char **argv)
{
	meta->argc = argc;
	meta->argv = argv;
	meta->error_msg = NULL;
	meta->sim_start_time = get_time_ms();
	meta->n_philos = philo_atouint(argv[1]);
	if (argc == 6)
		meta->opt_param_set = 1;
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
	if (meta->tt_death == 0 || meta->tt_eat == 0 | meta->tt_sleep == 0)
	{
		meta->error_msg = "Time to (die|eat|sleep) must be positive integers\n";
		return (1);
	}
	if (meta->opt_param_set == 0)
		return (0);
	if (meta->opt_param_set == 1 && meta->max_dinners == 0)
	{
		meta->error_msg = "Max number of dinners must be a positive integer\n";
		return (1);
	}
	return (0);
}
