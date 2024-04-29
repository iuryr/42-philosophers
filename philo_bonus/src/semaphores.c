/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:59:27 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/29 12:15:37 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

void	prepare_semaphores(t_semaphore_set *semaphore_set)
{
	semaphore_set->simulation_sem = sem_open("/simulation_sem", O_CREAT,
		0666, 0);
	semaphore_set->print_sem = sem_open("/print_sem", O_CREAT,
		0666, 1);
}
