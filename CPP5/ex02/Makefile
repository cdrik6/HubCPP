# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 23:32:02 by caguillo          #+#    #+#              #
#    Updated: 2024/12/07 03:50:31 by caguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	form

SRCS		=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp PresidentialPardonForm.cpp

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
 