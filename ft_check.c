/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:23 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/04 03:10:24 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int ac, char **av)
{
	int	i[2];

	i[0] = 0;
	while (++i[0] < ac)
	{
		i[1] = -1;
		while (av[i[0]][++i[1]] == ' ')
			;
		if (!av[i[0]][i[1]])
			error_arg();
		while (av[i[0]][++i[1]])
			if (!ft_isdigit(av[i[0]][i[1]]))
				error_arg();
	}
}

void	check_satiety(t_philo *philo)
{
	if (philo->n_meals == philo->data->max_meals)
		philo->data->satiety++;
}
