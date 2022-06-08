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

int		check_args(int ac, char **av)
{
	int		i[2];
	char	*arg;

	i[0] = 0;
	while (++i[0] < ac)
	{
		arg = ft_strtrim(av[i[0]], " ");
		i[1] = -1;
		if (!arg[++i[1]])
			if (error_arg(arg))
				return (1);
		while (arg[i[1]])
			if (!ft_isdigit(arg[i[1]++]))
				if (error_arg(arg))
					return (1);
		free(arg);
	}
	return (0);
}

void	check_satiety(t_philo *philo)
{
	if (philo->n_meals == philo->data->max_meals)
		philo->data->satiety++;
}
