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
		// printf("- ID : %d\n \
		// 		- n_philo : %d\n \
		// 		- t_die : %d\n \
		// 		- t_eat : %d\n \
		// 		- t_sleep : %d\n \
		// 		- max_meals : %d\n \
		// 		- if_die : %d\n \
		// 		- start : %d\n \n" \
		// 		, stc->id, stc->data->nbr_philo, stc->data->t_die, \
		// 		stc->data->t_eat, stc->data->t_sleep, \
		// 		stc->data->max_meals, stc->data->if_die, stc->data->t_start);
		printf("[%d] -> %d\n", stc->id, stc->n_meals);
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
	else if (ac == 5)
		(*data)->max_meals = -1;
	(*data)->satiety = 0;
	(*data)->head = NULL;
	// (*data)->t_start = gettimeofday();	//	start time
}

void	create_table(char **av, t_philo **lst, t_data *data)
{
	int	i;
	t_philo *node;

	i = 0;
	while (++i <= ft_atoi(av[1]))
	{
		node = ft_lstnew(i, data);
		ft_lstadd_back(lst, node);
		if (i == 1)
			data->head = node;
	}
}

void	philos_birth(t_philo **philos)
{
	t_philo	*head;

	head = *philos;
	while (head)
	{
		if (pthread_create(&(head->thread), NULL, (void *)routine, head))
			return ;
		head = head->next;
	}
}

void	ft_usleep(int time)
{
	long	max;

	max = time * 1000;
	usleep(max);
}
