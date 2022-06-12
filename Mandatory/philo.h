/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:53 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/12 11:03:00 by mbenbajj         ###   ########.fr       */
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

//	***********		STAMPS MACROS		*********** :
# define FORK_STMP "%ld -> %d has taken a fork\n"
# define EAT_STMP "%ld -> %d is eating\n"
# define SLEEP_STMP "%ld -> %d is sleeping\n"
# define THINK_STMP "%ld -> %d is thinking\n"
# define DIE_STMP "%ld -> %d died\n"
//	***********		Structs		*********** :
typedef struct s_data
{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_meals;
	int				if_die;
	long			t_start;
	int				satiety;
	struct s_philo	*head;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				n_meals;
	t_data			*data;
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
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);
//	***********		Lists Functions	*********** :
t_philo	*ft_lstnew(int id, t_data *data);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);

//	***********		Error Functions	*********** :
int		error_usage(void);
int		error_arg(char *arg);
void	error_null(void);

//	***********		Check Functions	*********** :
int		check_args(int ac, char **av);
void	check_satiety(t_philo *philo);

//	***********		Utils Functions	*********** :
void	print_stamp(char *str, long time, t_philo *philo);
long	ft_gettime(void);
int		null_arg(t_data *data);
void	ft_usleep(int time);
//	----
int		data_init(int ac, char **av, t_data **data);
void	create_table(char **av, t_philo **lst, t_data *data);
void	philos_birth(t_philo **philos);

//	***********		Routine Functions	*********** :
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	routine(void *philos);

#endif
