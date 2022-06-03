#ifndef PHILO_H
# define PHILO_H

//	***********		Includes	*********** :
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>

//	***********		Structs		*********** :
typedef struct s_data
{
	int		nbr_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_meals;
	int		if_die;
}	sh_data;

typedef struct s_philo 
{
	int				id;
	pthread_mutex_t	fork;
	int				last_meal;
	sh_data			data;
	struct s_philo	next;
}	t_philo;

//	***********		Libft Functions	*********** :
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
//	***********		Error Functions	*********** :
void	error_usage(void);
void	error_arg(void);

//	***********		Check Functions	*********** :
void	check_args(int ac, char **av);

#endif