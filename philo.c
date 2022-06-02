#include "philo.h"

int main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		error_usage();
	check_args(ac, av);
	ft_putendl_fd("\033[32m* CHECK DONE *\033[0m", 2);
}