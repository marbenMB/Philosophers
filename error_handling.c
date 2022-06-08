/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:16 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/08 10:26:33 by mbenbajj         ###   ########.fr       */
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
