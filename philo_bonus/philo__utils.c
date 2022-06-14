/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo__utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:04:12 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/13 18:58:17 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_stamp(char *str, long time, t_philo *philo)
{
	if (philo->data->if_die)
	{
		sem_wait(philo->data->print);
		printf(str, time, philo->id);
	}
	else
	{
		sem_wait(philo->data->print);
		printf(str, time, philo->id);
		sem_post(philo->data->print);
	}
}

int	null_arg(t_data *data)
{
	if (!data->nbr_philo || !data->t_die || !data->t_eat \
			|| !data->t_sleep || data->max_meals == 0)
	{
		error_null();
		return (1);
	}
	return (0);
}

long	ft_gettime(void)
{
	struct timeval	tp;
	long			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time);
}

void	ft_usleep(int time)
{
	long	start;

	start = ft_gettime();
	while (ft_gettime() - start <= time)
		usleep(100);
}

void	free_stc(t_philo *philos)
{
	t_philo	*back_up;

	while (philos)
	{
		back_up = philos->next;
		sem_close(philos->data->print);
		sem_close(philos->data->fork);
		free(philos);
		philos = back_up;
		if (philos && !philos->next)
			free(philos->data);
	}
}
