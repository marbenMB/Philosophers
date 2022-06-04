/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:47 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/04 03:10:49 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO : gettimeofday(); => the starting time
// TODO : <int check_meals;> if all philos eats max meals then it equals to 1 ; else 0
// TODO : create the routine && put a mutex to be locked the printing function if a philo is died

int	main(int ac, char **av)
{
	t_philo	*philos;
	t_data	*data;

	if (ac < 5 || ac > 6)
		error_usage();
	check_args(ac, av);
	ft_putendl_fd("\033[32m* +> CHECK DONE *\033[0m", 2);
	data_init(ac, av, &data);
	create_table(av, &philos, data);
	ft_putendl_fd("\033[32m* +> TABLE CREATED *\033[0m", 2);
	philos_birth(&philos);
	while (1)
	{
		if (philos->data->if_die)
			break ;
		if (philos->data->check_meals)
			break ;
	}
	return (0);
}
