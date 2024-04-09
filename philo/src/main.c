/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:28:51 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/09 16:24:45 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int argc, char **argv)
{
	t_meta	meta;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat "
			"time_to sleep [number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	set_meta(&meta, argc, argv);
	if (validate_inputs(&meta) != 0)
	{
		printf("%s", meta.error_msg);
		return (EXIT_FAILURE);
	}
	create_philos(&meta);
	start_simulation(meta);
	free(meta.philos);
	return (EXIT_SUCCESS);
}
