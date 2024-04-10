/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:28:47 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/10 12:20:45 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static int	aloc_philo_array(t_meta *meta)
{
	meta->philos = malloc(meta->n_philos * sizeof(t_philo));
	if (meta->philos == NULL)
		return (0);
	memset(meta->philos, 0, meta->n_philos * sizeof(t_philo));
	return (1);
}

static void	init_philos(t_meta *meta)
{
	unsigned int	i;

	i = -1;
	while (++i < meta->n_philos)
	{
		meta->philos[i].id = i + 1;
		meta->philos[i].state = THINKING;
		meta->philos[i].sim_start_time = meta->sim_start_time;
		meta->philos[i].tid = malloc(sizeof(pthread_t));
		meta->philos[i].tt_death = philo_atoul(meta->argv[2]);
		meta->philos[i].tt_eat = philo_atoul(meta->argv[3]);
		meta->philos[i].tt_sleep = philo_atoul(meta->argv[4]);
		meta->philos[i].last_timestamp = 0;
		meta->philos[i].last_meal = 0;
		if (meta->opt_param_set == 1)
		{
			meta->philos[i].opt_param_set = 1;
			meta->philos[i].max_dinners = philo_atouint(meta->argv[5]);
		}
		else
			meta->philos[i].opt_param_set = 0;
		meta->philos[i].log_mutex = &(meta->log_mutex);
	}
}

void	create_philos(t_meta *meta)
{
	if (aloc_philo_array(meta) == 0)
		exit(EXIT_FAILURE);
	init_philos(meta);
}

void	start_simulation(t_meta meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta.n_philos)
	{
		pthread_create(meta.philos[i].tid, NULL, routine, &(meta.philos[i]));
		i++;
	}
	i = 0;
	while (i < meta.n_philos)
	{
		pthread_join(*(meta.philos[i].tid), NULL);
		i++;
	}
	i = 0;
	while (i < meta.n_philos)
	{
		free(meta.philos[i].tid);
		i++;
	}
}
