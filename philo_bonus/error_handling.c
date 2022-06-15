/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:16 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/15 19:14:18 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_usage(void)
{
	ft_putendl_fd("\033[33m* USAGE ERROR *\033[0m", 2);
	return (1);
}

int	error_arg(char *arg)
{
	free(arg);
	ft_putendl_fd("\033[33m* ARG ERROR *\033[0m", 2);
	return (1);
}

void	error_null(void)
{
	ft_putendl_fd("\033[31m* NULL ARG *\033[0m", 2);
}

void	error_int(void)
{
	ft_putendl_fd("\033[31m* MAX INT *\033[0m", 2);
}
