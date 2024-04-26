/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:49:07 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/26 16:49:29 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

pid_t	safe_fork(void)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		exit(EXIT_FAILURE);
	return (child_pid);
}
