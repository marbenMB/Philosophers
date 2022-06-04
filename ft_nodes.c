#include "philo.h"

t_philo	*ft_lstnew(int	id, sh_data *data)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		exit (EXIT_FAILURE);
	new->id = id;
	new->data = data;
	new->next = NULL;
	return (new);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	if (!(*lst))
		(*lst) = new;
	else
		ft_lstlast(*lst)->next = new;
}