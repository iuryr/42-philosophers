/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:59:27 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/26 18:00:52 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

void	prepare_semaphores(sem_t ***semaphores)
{
	*semaphores = malloc(sizeof(sem_t **));
	(*semaphores)[0] = sem_open("/start_simulation", O_CREAT, 666, 0);
}
