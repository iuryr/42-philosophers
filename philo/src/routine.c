/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:07:10 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/08 18:36:02 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	eat(int time_to_eat)
{
	struct timeval	start_time;
	struct timeval	now;

	gettimeofday(&start_time, NULL);
	printf("%ld - Philo is eating\n", start_time.tv_usec);
	while (42)
	{
		gettimeofday(&now, NULL);
		if (now.tv_sec - start_time.tv_usec > (long) time_to_eat)
		{
			printf("Finished eating...\n");
			break ;
		}
	}
}
