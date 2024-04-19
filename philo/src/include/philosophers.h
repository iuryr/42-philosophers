/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:29:33 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/19 16:00:44 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DED
}	t_state;

typedef struct s_simdata
{
	unsigned int	n_philos;
	unsigned long	sim_start_time;
	unsigned long	tt_death;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned int	max_dinners;
	unsigned int	stuffed_philos;
	pthread_mutex_t	stuffed_mutex;
	pthread_mutex_t	sim_mutex;
	pthread_mutex_t	*forks;
	int				go_on;
}	t_simdata;

typedef struct s_philo
{
	pthread_t		*tid;
	unsigned int	id;
	t_state			state;
	t_simdata		*simdata;
	unsigned long	sim_start_time;
	unsigned int	n_dinners;
	unsigned int	max_dinners;
	unsigned long	last_meal;
	unsigned long	last_sleep;
	unsigned long	last_think;
	unsigned long	time_of_death;
	pthread_mutex_t	*log_mutex;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;

typedef struct s_meta
{
	char			*error_msg;
	t_simdata		simdata;
	unsigned int	n_philos;
	unsigned int	opt_param_set;
	pthread_mutex_t	log_mutex;
	t_philo			*philos;
	pthread_t		overseer;
}	t_meta;

//philos
int				create_threads(t_meta *meta);
void			start_simulation(t_meta *meta);

//routine
void			*routine(void *arg);
void			eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			think(t_philo *philo);
void			change_state(char c, t_philo *philo);
int				grab_forks(t_philo *philo);
int				grab_forks_even(t_philo *philo);
int				grab_forks_odd(t_philo *philo);

//overseer
void			*oversee(void *arg);
int				check_philo_alive(t_meta *meta, unsigned int i);

//input validation
void			set_meta(t_meta *meta, int argc, char **argv);
int				validate_inputs(t_meta *meta);

//utils
unsigned int	philo_atouint(const char *nptr);
unsigned int	philo_atoul(const char *nptr);
unsigned long	get_time_ms(void);
unsigned long	get_timestamp(t_meta *meta);
unsigned long	philo_get_timestamp(t_philo *philo);
void			print_log(t_philo *philo);
void			print_fork(t_philo *philo);
int				get_philo_state(t_philo *philo);
int				read_sim_status(t_simdata *simdata);
void			change_sim_status(t_simdata *simdata);
unsigned int	read_stuffed_philos(t_simdata *simdata);
void			update_stuffed_philos(t_simdata *simdata);

#endif //PHILOSOPHERS_H
