#include "philo.h"

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(500);
	pthread_mutex_lock(&philo->fork);
	printf("%d has taken a fork\n", philo->id);
	if (philo->next)
		pthread_mutex_lock(&philo->next->fork);
	else
		pthread_mutex_lock(&philo->data->head->fork);
	printf("%d has taken a fork\n", philo->id);
	printf("%d is eating\n", philo->id);
	ft_usleep(philo->data->t_eat);
	if (philo->next)
		pthread_mutex_unlock(&philo->next->fork);
	else
		pthread_mutex_unlock(&philo->data->head->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	sleeping(t_philo *philo)
{
	printf("%d is sleeping\n", philo->id);
	ft_usleep(philo->data->t_sleep);
}

void	thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
}

void	routine(void *philos)
{
	t_philo *back_up;

	back_up = (t_philo *)philos;
	while(back_up->data->if_die == 0)
	{
		// eating  
		eating(back_up);
		// sleeping
		sleeping(back_up);
		// thinking
		thinking(back_up);
	}
}