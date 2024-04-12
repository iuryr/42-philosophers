/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:29:33 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/12 16:57:30 by iusantos         ###   ########.fr       */
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
	unsigned long	sim_start_time;
	unsigned long	tt_death;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned int	max_dinners;
	int				go_on;
}	t_simdata;

typedef struct s_philo
{
	pthread_t		*tid;
	unsigned int	id;
	t_state			state;
	t_simdata		*simdata;
	unsigned long	sim_start_time;
	unsigned long	tt_death;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned int	n_dinners;
	unsigned int	opt_param_set;
	unsigned int	max_dinners;
	unsigned long	last_timestamp;
	unsigned long	last_meal;
	pthread_mutex_t	*log_mutex;
	pthread_mutex_t	state_mutex;
}	t_philo;

typedef struct s_meta
{
	char			*error_msg;
	t_simdata		data;
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
int				get_philo_state(t_philo *philo);

#endif //PHILOSOPHERS_H
