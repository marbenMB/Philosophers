/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:11:01 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/04 03:11:03 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_stc(t_philo *stc)
{
	printf("\033[32m* ------------------ *\033[0m\n");
	while (stc)
	{
		printf("- ID : %d\n \
				- n_philo : %d\n \
				- t_die : %d\n \
				- t_eat : %d\n \
				- t_sleep : %d\n \
				- n_meals : %d\n \
				- if_die : %d\n \
				- start : %d\n \n" \
				, stc->id, stc->data->nbr_philo, stc->data->t_die, \
				stc->data->t_eat, stc->data->t_sleep, \
				stc->data->n_meals, stc->data->if_die, stc->data->t_start);
		stc = stc->next;
	}
}

void	data_init(int ac, char **av, t_data **data)
{
	// long	time;

	(*data) = (t_data *)malloc(sizeof(t_data));
	if (!(*data))
		return ;
	(*data)->if_die = 0;
	(*data)->nbr_philo = ft_atoi(av[1]);
	(*data)->t_die = ft_atoi(av[2]);
	(*data)->t_eat = ft_atoi(av[3]);
	(*data)->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->max_meals = ft_atoi(av[5]);
	
	// (*data)->t_start = gettimeofday();	//	start time
}

void	create_table(char **av, t_philo **lst, t_data *data)
{
	int	i;

	i = 0;
	while (++i <= ft_atoi(av[1]))
		ft_lstadd_back(lst, ft_lstnew(i, data));
}

void	routine(void)
{
	static int	i;

	printf("\033[35m* -+-> Thread Created : %d*\033[0m\n", ++i);
}

void	philos_birth(t_philo **philos)
{
	t_philo	*head;

	head = (*philos);
	while (*philos)
	{
		if (pthread_create(&(*philos)->thread, NULL, (void *)routine, NULL))
			return ;
		(*philos) = (*philos)->next;
	}
	*philos = head;
}
