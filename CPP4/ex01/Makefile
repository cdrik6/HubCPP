# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 23:32:02 by caguillo          #+#    #+#              #
#    Updated: 2024/11/15 03:20:58 by caguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	brain

SRCS		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -Wshadow

OBJS		=	$(SRCS:.cpp=.o)

$(NAME):	$(OBJS)			
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			
all:		$(NAME)

re: 		fclean all
			
clean:			
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)
			
.PHONY: 	all clean fclean re
 