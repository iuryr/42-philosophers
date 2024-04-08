/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:29:33 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/08 18:36:35 by iusantos         ###   ########.fr       */
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

typedef struct s_meta
{
	int				argc;
	char			**argv;
	char			*error_msg;
	unsigned int	n_philos;
	unsigned long	tt_death;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned int	opt_param_set;
	unsigned int	max_dinners;
}	t_meta;

//routine
void			eat(int time_to_eat);

//input validation
void			set_meta(t_meta *meta, int argc, char **argv);
int				validate_inputs(t_meta *meta);

//utils
unsigned int	philo_atouint(const char *nptr);
unsigned int	philo_atoul(const char *nptr);

#endif //PHILOSOPHERS_H
