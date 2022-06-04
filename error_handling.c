/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:10:16 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/04 03:10:17 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_usage(void)
{
	ft_putendl_fd("\033[33m* USAGE ERROR *\033[0m", 2);
	exit (EXIT_FAILURE);
}

void	error_arg(void)
{
	ft_putendl_fd("\033[33m* ARG ERROR *\033[0m", 2);
	exit (EXIT_FAILURE);
}
