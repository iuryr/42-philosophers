/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:40 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/26 14:43:44 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

/*** input validation ***/

/*
* validate inputs
* @param argc argument count
* @param argv arguments array
*/
int				validate_inputs(int argc, char **argv);

/********************** utils **********************/

/**
* ascii to int
* @param nptr pointer to string
*/
unsigned int	philo_atouint(const char *nptr);
/**
* ascii to long
* @param nptr pointer to string
*/
unsigned int	philo_atoul(const char *nptr);

#endif //PHILOSOPHERS_BONUS_H
