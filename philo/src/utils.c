/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:05:00 by iusantos          #+#    #+#             */
/*   Updated: 2024/04/09 14:43:32 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static int	philo_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

static int	philo_isspace(int c)
{
	if ((c >= 9 & c <= 13) || c == 32)
		return (c);
	else
		return (0);
}

unsigned int	philo_atouint(const char *nptr)
{
	unsigned int	number;

	number = 0;
	while (philo_isspace(*nptr) != 0)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			return (number);
		nptr++;
	}
	while (philo_isdigit(*nptr))
	{
		number = number * 10;
		number = number + (*nptr - '0');
		nptr++;
	}
	return (number);
}

unsigned int	philo_atoul(const char *nptr)
{
	unsigned long	number;

	number = 0;
	while (philo_isspace(*nptr) != 0)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			return (number);
		nptr++;
	}
	while (philo_isdigit(*nptr))
	{
		number = number * 10;
		number = number + (*nptr - '0');
		nptr++;
	}
	return (number);
}

unsigned long	get_time_ms(void)
{
	unsigned long	start_time_ms;
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	start_time_ms = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	return (start_time_ms);
}
