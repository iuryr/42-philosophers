/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:29:33 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/11 16:50:23 by iusantos         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		*tid;
	unsigned int	id;
	t_state			state;
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
	int				argc;
	char			**argv;
	char			*error_msg;
	unsigned long	sim_start_time;
	unsigned int	n_philos;
	unsigned long	tt_death;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned int	opt_param_set;
	unsigned int	max_dinners;
	pthread_mutex_t	log_mutex;
	t_philo			*philos;
	pthread_t		overseer;
}	t_meta;

//philos
void			create_threads(t_meta *meta);
void			start_simulation(t_meta meta);

//routine
void			*routine(void *arg);
void			eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			think(t_philo *philo);
void			change_state(char c, t_philo *philo);

//overseer

void			*oversee(void *arg);
int				check_philo_alive(t_philo philo);
void			kill_others(t_meta *meta);
//input validation
void			set_meta(t_meta *meta, int argc, char **argv);
int				validate_inputs(t_meta *meta);

//utils
unsigned int	philo_atouint(const char *nptr);
unsigned int	philo_atoul(const char *nptr);
unsigned long	get_time_ms(void);
unsigned long	get_timestamp(t_philo *philo);
void			print_log(t_philo *philo);

#endif //PHILOSOPHERS_H
