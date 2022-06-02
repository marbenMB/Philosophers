#include "philo.h"

void	error_usage(void)
{
	ft_putendl_fd("\033[33m* USAGE ERROR *\033[0m", 2);
	exit (EXIT_FAILURE);
}

void	error_arg(void)
{
	ft_putendl_fd("\033[33m* ARG ERROR *\033[0m", 2);
	exit (EXIT_FAILURE);
}