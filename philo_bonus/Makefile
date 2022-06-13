# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 03:10:08 by mbenbajj          #+#    #+#              #
#    Updated: 2022/06/13 19:03:16 by mbenbajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = libft.c ft_libft.c philo.c ft_check.c error_handling.c philo_utils.c philo__utils.c ft_nodes.c ft_routine.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -pthread

all : $(NAME)

$(NAME) : $(OBJ) philo.h
	cc $(CFLAGS) $(SRC) -o $(NAME) -g

clean :
	rm $(OBJ)

fclean :
	rm -rf $(OBJ) $(NAME) philo.dSYM

re : fclean all

.PHONEY : all clean fclean re
