/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:11:01 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/10 00:05:36 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_stamp(char *str, long time, t_philo *philo)
{
	if (philo->data->if_die)
	{
		pthread_mutex_lock(&philo->data->print);
		printf(str, time, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->data->print);
		printf(str, time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
}

long	ft_gettime(void)
{
	struct timeval	tp;
	long			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time);
}

int	null_arg(t_data *data)
{
	if (!data->nbr_philo || !data->t_die || !data->t_eat \
			|| !data->t_sleep || data->max_meals == 0)
		return (1);
	return (0);
}

int	data_init(int ac, char **av, t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (!(*data))
		return (1);
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
	if (null_arg(*data))
	{
		free(*data);
		return (1);
	}
	(*data)->t_start = 0;
	if (pthread_mutex_init(&((*data)->print), NULL))
		return (1);
	return (0);
}

void	create_table(char **av, t_philo **lst, t_data *data)
{
	int		i;
	t_philo	*node;

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
	(*philos)->data->t_start = ft_gettime();
	while (head)
	{
		if (pthread_create(&(head->thread), NULL, (void *)routine, head))
			return ;
		head->last_meal = ft_gettime();
		head = head->next;
	}
}

void	ft_usleep(int time)
{
	// long	max;
	long	start;

	start = ft_gettime();

	while (ft_gettime() - start <= time)
		usleep(100);
	// max = time * 1000;
	// usleep(max);
}
