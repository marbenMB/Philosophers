/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:53 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/04 03:10:55 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//	***********		Includes	*********** :
# include <libc.h>
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
	int		max_meals;
	int		check_meals;
	int		if_die;
	long	t_start;
	int		satiety;
	struct s_philo *head;
}	t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				n_meals;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	print;
	struct s_philo	*next;
}	t_philo;

//	***********		Libft Functions	*********** :
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
//	***********		Lists Functions	*********** :
t_philo	*ft_lstnew(int id, t_data *data);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);

//	***********		Error Functions	*********** :
void	error_usage(void);
void	error_arg(void);

//	***********		Check Functions	*********** :
void	check_args(int ac, char **av);
void	check_satiety(t_philo *philo);

//	***********		Utils Functions	*********** :
void	print_stc(t_philo *stc);
void	data_init(int ac, char **av, t_data **data);
void	create_table(char **av, t_philo **lst, t_data *data);
void	philos_birth(t_philo **philos);
void	ft_usleep(int time);

//	***********		Routine Functions	*********** :
void	eating(t_philo *philo);
void	routine(void *philos);

#endif
