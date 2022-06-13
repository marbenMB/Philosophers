/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:47 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/13 11:41:19 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO : algo -> forking -> create a thread in every process that loops to check if philo eats max_meals (-> exit(n)) or the philo is died (-> exit(m)); -> Waitpid(-1, &status, NULL);
// TODO : if the status is equivalent to died philo exit -> kill all process || equivalent that the philo eats max_meals -> wait others and so one

void	loop(t_philo *philos)
{
	int r;
	t_philo *node;

	r = 0;
	node = philos;
	while (philos)
	{
		waitpid(-1, &r, 0);
		if (r == 0)
		{
			while (node)
			{
				kill(node->pid, SIGKILL);
				node = node->next;
			}
			exit (0);
		}
		else
			philos = philos->next;
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
