/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:47 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/08 10:18:20 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO : Parsing cases : test with 0 and negation
// TODO : put a mutex to be locked the printing function if a philo is died
// TODO : Protect usleep();   
// TODO : gettimeofday(); => the starting time

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
	while (1)
	{
		if (philos->data->if_die)
			break ;
		if (philos->data->satiety >= philos->data->nbr_philo)
		{
			philos->data->if_die = 1;
			print_stc(philos->data->head);
			break ;
		}
	}
	return (0);
}
