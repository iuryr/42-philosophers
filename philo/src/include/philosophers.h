/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:29:33 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/09 18:25:03 by iusantos         ###   ########.fr       */
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
	unsigned int	opt_param_set;
	unsigned int	max_dinners;
	unsigned long	last_meal;
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
	t_philo			*philos;
}	t_meta;

//philos
void			init_philos(t_meta *meta);
void			start_simulation(t_meta meta);

//routine
void			*routine(void *arg);
void			eat(t_philo *philo);

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
