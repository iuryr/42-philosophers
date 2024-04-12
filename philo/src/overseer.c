/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overseer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:12:26 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/12 17:28:03 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*oversee(void *arg)
{
	t_meta			*meta;
	unsigned int	i;

	meta = (t_meta *) arg;
	usleep(20000);
	i = 0;
	while (i < meta->n_philos && meta->data.go_on)
	{
		if (check_philo_alive(meta, i) == 0)
		{
			if (meta->opt_param_set == 1
				&& meta->philos[i].n_dinners == meta->data.max_dinners)
				break ;
			change_state('D', &(meta->philos[i]));
			print_log(&(meta->philos[i]));
			meta->data.go_on = 0;
			break ;
		}
		i++;
		if (i == meta->n_philos)
			i = 0;
	}
	return (NULL);
}

int	check_philo_alive(t_meta *meta, unsigned int i)
{
	pthread_mutex_lock(&(meta->philos[i].state_mutex));
	if ((get_timestamp(meta) - meta->philos[i].last_meal < meta->data.tt_death))
	{
		pthread_mutex_unlock(&(meta->philos[i].state_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(meta->philos[i].state_mutex));
	return (0);
}

int	get_philo_state(t_philo *philo)
{
	pthread_mutex_lock(&(philo->state_mutex));
	if (philo->state == SLEEPING)
	{
		pthread_mutex_unlock(&(philo->state_mutex));
		return SLEEPING;
	}
	if (philo->state == EATING)
	{
		pthread_mutex_unlock(&(philo->state_mutex));
		return EATING;
	}
	if (philo->state == DED)
	{
		pthread_mutex_unlock(&(philo->state_mutex));
		return DED;
	}
	else
	{
		pthread_mutex_unlock(&(philo->state_mutex));
		return THINKING;
	}
}
