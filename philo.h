#ifndef PHILO_H
# define PHILO_H

//	***********		Includes	*********** :
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
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
	int		t_start;
}	sh_data; 

typedef struct s_philo 
{
	int				id;
	int				last_meal;
	sh_data			*data;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_philo	*next;
}	t_philo;


//	***********		Libft Functions	*********** :
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
//	***********		Lists Functions	*********** :
t_philo	*ft_lstnew(int	id, sh_data *data);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);

//	***********		Error Functions	*********** :
void	error_usage(void);
void	error_arg(void);

//	***********		Check Functions	*********** :
void	check_args(int ac, char **av);

//	***********		Utils Functions	*********** :
void	print_stc(t_philo *stc);
void	data_init(int ac, char **av, sh_data **data);
void 	create_table(char **av, t_philo **lst, sh_data *data);

#endif