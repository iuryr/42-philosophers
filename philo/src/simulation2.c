/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:59:29 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/24 18:00:02 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	read_sim_status(t_simdata *simdata)
{
	pthread_mutex_lock(&(simdata->sim_mutex));
	if (simdata->go_on == 1)
	{
		pthread_mutex_unlock(&(simdata->sim_mutex));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(simdata->sim_mutex));
		return (0);
	}
}

void	change_sim_status(t_simdata *simdata)
{
	pthread_mutex_lock(&(simdata->sim_mutex));
	if (simdata->go_on == 1)
		simdata->go_on = 0;
	else
		simdata->go_on = 1;
	pthread_mutex_unlock(&(simdata->sim_mutex));
}

unsigned int	read_stuffed_philos(t_simdata *simdata)
{
	unsigned int	stuffed_philos;

	pthread_mutex_lock(&(simdata->stuffed_mutex));
	stuffed_philos = simdata->stuffed_philos;
	pthread_mutex_unlock(&(simdata->stuffed_mutex));
	return (stuffed_philos);
}

void	update_stuffed_philos(t_simdata *simdata)
{
	pthread_mutex_lock(&(simdata->stuffed_mutex));
	simdata->stuffed_philos++;
	pthread_mutex_unlock(&(simdata->stuffed_mutex));
}
