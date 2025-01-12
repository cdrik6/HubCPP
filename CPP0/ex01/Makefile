# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 23:32:02 by caguillo          #+#    #+#              #
#    Updated: 2024/10/21 02:42:33 by caguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook

SRCS		=	main.cpp PhoneBook.cpp Contact.cpp

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 

OBJS		=	$(SRCS:.cpp=.o)

%.o:%.cpp		
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)			
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			
all:		$(NAME)

re: 		fclean all
			
clean:			
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)
			
.PHONY: 	all clean fclean re 
