/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:14:29 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/10 16:20:34 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_stamp(FORK_STMP, ft_gettime() - philo->data->t_start, philo);
	if (philo->next)
		pthread_mutex_lock(&philo->next->fork);
	else
		pthread_mutex_lock(&philo->data->head->fork);
	print_stamp(FORK_STMP, ft_gettime() - philo->data->t_start, philo);
	print_stamp(EAT_STMP, ft_gettime() - philo->data->t_start, philo);
	philo->n_meals++;
	check_satiety(philo);
	philo->last_meal = ft_gettime();
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->fork);
	if (philo->next)
		pthread_mutex_unlock(&philo->next->fork);
	else
		pthread_mutex_unlock(&philo->data->head->fork);
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
	back_up->data->t_start = ft_gettime();
	if (back_up->id % 2 == 0)
		usleep(500);
	while (back_up->data->if_die == 0)
	{
		eating(back_up);
		if (back_up->data->satiety == back_up->data->nbr_philo)
			break ;
		sleeping(back_up);
		thinking(back_up);
	}
}
