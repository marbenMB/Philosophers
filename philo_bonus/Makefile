# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 03:10:08 by mbenbajj          #+#    #+#              #
#    Updated: 2022/06/14 19:06:34 by mbenbajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
SRC = libft.c ft_libft.c philo.c ft_check.c error_handling.c philo_utils.c philo__utils.c ft_nodes.c ft_routine.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -pthread

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	cc $(CFLAGS) -c $< -o $@

clean :
	rm $(OBJ)

fclean :
	rm -rf $(OBJ) $(NAME) philo_bonus.dSYM

re : fclean all

.PHONEY : all clean fclean re
