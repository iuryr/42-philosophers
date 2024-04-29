/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:41:37 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/29 18:25:36 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

int	am_i_alive(t_philo *philo, t_semaphore_set *semaphore_set)
{
	if (get_timestamp(philo) - philo->last_meal <= philo->tt_death)
	{
		return (1);
	}
	else
	{
		philo->time_of_death = get_timestamp(philo);
		print_log('D', philo, semaphore_set);
		close_semaphores(semaphore_set);
		exit(2);
	}
}
