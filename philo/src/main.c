/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:28:51 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/05 16:54:21 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

typedef struct s_philo
{
	pthread_mutex_t lock;
	int i;
} t_philo_arg;

void	*thread_print(void *arg)
{
	static int tid;
	
	pthread_mutex_lock(&(((t_philo_arg *)arg)->lock));
	printf("Thread %d criada.\n", ++tid);
	printf("Thread %d: i = %d\n", tid, ((t_philo_arg *)arg)->i++);
	pthread_mutex_unlock(&(((t_philo_arg *)arg)->lock));
	pthread_detach(pthread_self()); //solves memory leak
	return NULL;
}

//arg[1]: number of philos
//arg[2]: time to die
//arg[3]: time to eat
//arg[4]: time to sleep
//arg[5]: max number of cicles
int	main(int argc, char **argv)
{
	if (argc < 4 || argc > 5)
	{
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat"
			" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	
	unsigned int n = atoi(argv[1]);
	pthread_t	philos[n];

	t_philo_arg arg;
	arg.i = 0;

	pthread_mutex_init(&arg.lock, NULL);

	unsigned int i = 0;
	while (i < n)
	{
		pthread_create(&(philos[i]), NULL, &thread_print, &arg);
		i++;
	}

	sleep(5);
	pthread_mutex_destroy(&arg.lock);
	return (EXIT_SUCCESS);
}
