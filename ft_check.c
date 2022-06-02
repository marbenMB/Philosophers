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