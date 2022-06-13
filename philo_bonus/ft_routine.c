/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:14:29 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/13 20:14:50 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->data->fork);
	print_stamp(FORK_STMP, ft_gettime() - philo->data->t_start, philo);
	sem_wait(philo->data->fork);
	print_stamp(FORK_STMP, ft_gettime() - philo->data->t_start, philo);
	print_stamp(EAT_STMP, ft_gettime() - philo->data->t_start, philo);
	philo->n_meals++;
	philo->last_meal = ft_gettime();
	ft_usleep(philo->data->t_eat);
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
}

void	sleeping(t_philo *philo)
{
	print_stamp(SLEEP_STMP, ft_gettime() - philo->data->t_start, philo);
	ft_usleep(philo->data->t_sleep);
}

void	thinking(t_philo *philo)
{
	print_stamp(THINK_STMP, ft_gettime() - philo->data->t_start, philo);
}

void	routine(void *philos)
{
	t_philo	*back_up;

	back_up = (t_philo *)philos;
	pthread_create(&back_up->thread, NULL, (void *)check_satiety, back_up);
	if (back_up->id % 2 == 0)
		usleep(500);
	while (back_up->data->if_die == 0)
	{
		eating(back_up);
		if (back_up->data->satiety)
			break ;
		sleeping(back_up);
		thinking(back_up);
	}
	if (back_up->data->satiety == 1)
		exit(1);
	if (back_up->data->if_die == 1)
		exit(0);
}
