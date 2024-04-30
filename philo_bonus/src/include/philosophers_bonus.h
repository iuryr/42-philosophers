/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:40 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/30 17:12:24 by iusantos         ###   ########.fr       */
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

# ifndef DED
# define DED 2
# endif //DED

typedef struct s_semaphore_set
{
	sem_t	*simulation_sem;
	sem_t	*print_sem;
	sem_t	*reach_table_sem;
	sem_t	*forks_sem;
}	t_semaphore_set;

typedef struct s_philo
{
	unsigned int	id;
	unsigned long	tt_death;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned long	sim_start_time;
	unsigned long	last_meal;
	unsigned long	last_sleep;
	unsigned long	last_think;
	unsigned long	last_grab;
	unsigned long	time_of_death;
	unsigned int	n_dinners;
	unsigned int	opt_param;
	unsigned int	max_dinners;
}	t_philo;

typedef struct s_child_info
{
	pid_t	child[200];
	int		exit_status;
}	t_child_info;

/*** input validation ***/

/*
* validate inputs
* @param argc argument count
* @param argv arguments array
*/
int				validate_inputs(int argc, char **argv);

/********************** simulation *****************/
void			prepare_philo(t_philo *philo, int argc, char **argv);
void			unlink_semaphores(void);
void			prepare_semaphores(t_semaphore_set *semaphore_set, char **argv);
void			close_semaphores(t_semaphore_set *semaphore_set);
void			routine(t_philo *philo, t_semaphore_set *semaphore_set);
int				am_i_alive(t_philo *philo, t_semaphore_set *semaphore_set);

/********************** time *****************/
unsigned long	get_time_ms(void);
unsigned long	get_timestamp(t_philo *philo);

/********************** logging *****************/
int				print_log(char c, t_philo *philo,
					t_semaphore_set *semaphore_set);

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

/*************** wrapper functions ******************/
pid_t			safe_fork(void);

#endif //PHILOSOPHERS_BONUS_H
