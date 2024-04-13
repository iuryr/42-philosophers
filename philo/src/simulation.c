/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:28:47 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/13 15:14:03 by iusantos         ###   ########.fr       */
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
		meta->philos[i].simdata = &(meta->simdata);
		meta->philos[i].tid = malloc(sizeof(pthread_t));
		// meta->philos[i].tt_death = philo_atoul(meta->argv[2]);
		// meta->philos[i].tt_eat = philo_atoul(meta->argv[3]);
		// meta->philos[i].tt_sleep = philo_atoul(meta->argv[4]);
		meta->philos[i].last_meal = 0;
		// if (meta->opt_param_set == 1)
		// {
		// 	meta->philos[i].opt_param_set = 1;
		// 	meta->philos[i].max_dinners = philo_atouint(meta->data.max_dinners);
		// }
		// else
		// 	meta->philos[i].opt_param_set = 0;
		meta->philos[i].log_mutex = &(meta->log_mutex);
		meta->philos[i].n_dinners = 0;
		pthread_mutex_init(&(meta->philos[i].state_mutex), NULL);
	}
}

int	create_threads(t_meta *meta)
{
	if (aloc_philo_array(meta) == 0)
		return (1);
	init_philos(meta);
	return (0);
}

void	start_simulation(t_meta *meta)
{
	unsigned int	i;

	meta->simdata.sim_start_time = get_time_ms();
	pthread_create(&(meta->overseer), NULL, oversee, meta);
	i = 0;
	while (i < meta->n_philos)
	{
		meta->philos[i].sim_start_time = meta->simdata.sim_start_time;
		pthread_create(meta->philos[i].tid, NULL, routine, &(meta->philos[i]));
		i++;
	}
	i = 0;
	while (i < meta->n_philos)
	{
		pthread_join(*(meta->philos[i].tid), NULL);
		i++;
	}
	pthread_join(meta->overseer, NULL);
	i = 0;
	while (i < meta->n_philos)
	{
		pthread_mutex_destroy(&(meta->philos[i].state_mutex));
		free(meta->philos[i].tid);
		i++;
	}
}
