/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:47 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/12 11:22:32 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop(t_philo *philos)
{
	while (1)
	{
		if ((ft_gettime()) - philos->last_meal >= philos->data->t_die)
		{
			philos->data->if_die = 1;
			print_stamp(DIE_STMP, ft_gettime() - philos->data->t_start, philos);
			break ;
		}
		if (philos->data->satiety >= philos->data->nbr_philo)
		{
			philos->data->if_die = 1;
			break ;
		}
		if (philos->next)
			philos = philos->next;
		else
			philos = philos->data->head;
		usleep(800);
	}
}

int	main(int ac, char **av)
{
	t_philo	*philos;
	t_data	*data;

	if (ac < 5 || ac > 6)
		if (error_usage())
			return (1);
	if (check_args(ac, av))
		return (1);
	if (data_init(ac, av, &data))
		return (1);
	create_table(av, &philos, data);
	philos_birth(&philos);
	loop(philos);
	return (0);
}
