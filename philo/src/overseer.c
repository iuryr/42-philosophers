/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:12:26 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/11 17:02:15 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*oversee(void *arg)
{
	t_meta	*meta;
	unsigned int i;

	meta = (t_meta *) arg;
	usleep(10000);
	i = 0;
	while(42)
	{
		while (i < meta->n_philos)
		{
			if (check_philo_alive(meta->philos[i]) == 0)
			{
				if (meta->opt_param_set == 1
					&& meta->philos[i].n_dinners == meta->max_dinners)
					break;
				meta->philos[i].last_timestamp = get_timestamp(meta->philos);
				change_state('D', &(meta->philos[i]));
				print_log(&(meta->philos[i]));
				kill_others(meta);
				break;
			}
			i++;
			if (i == meta->n_philos)
				i = 0;
		}
		break;
	}
	return (NULL);
}

int	check_philo_alive(t_philo philo)
{
	if ((get_timestamp(&philo) - philo.last_meal < philo.tt_death))
		return 1;
	return 0;
}

void	kill_others(t_meta *meta)
{
	unsigned int i;

	i = 0;
	while (i < meta->n_philos)
	{
		change_state('D', &(meta->philos[i]));
		i++;
	}
}
