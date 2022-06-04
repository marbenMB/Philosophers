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
				,stc->id, stc->data->nbr_philo, stc->data->t_die, \
				stc->data->t_eat, stc->data->t_sleep, \
				stc->data->n_meals, stc->data->if_die, stc->data->t_start);
		stc = stc->next;
	}
}

void	data_init(int ac, char **av, sh_data **data)
{
	(*data) = (sh_data *)malloc(sizeof(sh_data));
	if (!(*data))
		exit (EXIT_FAILURE);
	(*data)->if_die = 0;
	(*data)->nbr_philo = ft_atoi(av[1]);
	(*data)->t_die = ft_atoi(av[2]);
	(*data)->t_eat = ft_atoi(av[3]);
	(*data)->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->n_meals = ft_atoi(av[5]);
	// (*data)->t_start = gettimeofday();	//	start time
}

void create_table(char **av, t_philo **lst, sh_data *data)
{
	int	i;

	i = 0;
	while (++i <= ft_atoi(av[1]))
		ft_lstadd_back(lst, ft_lstnew(i, data));
}
