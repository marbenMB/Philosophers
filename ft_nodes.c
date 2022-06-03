#include "philo.h"

t_philo	*ft_lstnew(int	id, sh_data *data)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	new->id = id;
	new->data = *data;

	return (new);
}