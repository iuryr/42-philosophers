/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:20:11 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/26 16:39:44 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

void	prepare_philo(t_philo *philo, int argc, char **argv)
{
	philo->tt_death = philo_atoul(argv[2]);
	philo->tt_eat = philo_atoul(argv[3]);
	philo->tt_sleep = philo_atoul(argv[4]);
	philo->last_meal = 0;
	philo->n_dinners = 0;
	if (argc == 6)
	{
		philo->opt_param = 1;
		philo->max_dinners = philo_atouint(argv[5]);
	}
	else
	{
		philo->opt_param = 0;
		philo->max_dinners = 0;
	}
}
