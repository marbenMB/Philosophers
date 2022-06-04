# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 03:10:08 by mbenbajj          #+#    #+#              #
#    Updated: 2022/06/04 03:10:10 by mbenbajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = libft.c philo.c ft_check.c error_handling.c philo_utils.c ft_nodes.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -pthread

all : $(NAME)

$(NAME) : $(OBJ) philo.h
	cc $(FLAGS) $(SRC) -o $(NAME) -g

clean :
	rm $(OBJ)

fclean :
	rm -rf $(OBJ) $(NAME) philo.dSYM

re : fclean all

.PHONEY : all clean fclean re
