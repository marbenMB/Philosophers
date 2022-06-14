/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:23 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/14 17:21:02 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
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

void	check_satiety(void *philo)
{
	t_philo	*node;

	node = (t_philo *)philo;
	while (1)
	{
		if (node->n_meals == node->data->max_meals)
		{
			node->data->satiety = 1;
			return ;
		}
		if ((ft_gettime()) - node->last_meal >= node->data->t_die)
		{
			node->data->if_die = 1;
			print_stamp(DIE_STMP, ft_gettime() - node->data->t_start, node);
			exit(0);
		}
		usleep(50);
	}
}

void	ft_exit(int status, t_philo *lst)
{
	free_stc(lst);
	exit(status);
}
