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

int	main(int ac, char **av)
{
	t_philo	*one;
	t_data	*data;

	if (ac < 5 || ac > 6)
		error_usage();
	check_args(ac, av);
	ft_putendl_fd("\033[32m* +> CHECK DONE *\033[0m", 2);
	data_init(ac, av, &data);
	create_table(av, &one, data);
	ft_putendl_fd("\033[32m* +> TABLE CREATED *\033[0m", 2);
	return (0);
}
