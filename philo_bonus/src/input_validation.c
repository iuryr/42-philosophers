/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:04:18 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/26 14:42:14 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

static int	check_arg_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo_bonus number_of_philos time_to_die time_to_eat "
			"time_to_sleep [max_dinners]\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int	check_arg_values(int argc, char **argv)
{
	if (philo_atouint(argv[1]) <= 0
		|| philo_atoul(argv[2]) <= 0
		|| philo_atoul(argv[3]) <= 0
		|| philo_atoul(argv[4]) <= 0)
	{
		printf("Invalid input: number_of_philos, time_to_die, time_to_eat and "
			"time_to_sleep must all be positive integers\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 6 && philo_atouint(argv[5]) <= 0)
	{
		printf("Invalid input: optional parameter max_dinners must be a "
			"positive integer\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	validate_inputs(int argc, char **argv)
{
	if (check_arg_count(argc) == 0 && check_arg_values(argc, argv) == 0)
	{
		return (0);
	}
	exit(EXIT_FAILURE);
}
