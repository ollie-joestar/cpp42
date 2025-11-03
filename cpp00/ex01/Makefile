# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 10:52:52 by oohnivch          #+#    #+#              #
#    Updated: 2025/09/09 12:07:51 by oohnivch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook
CC		= c++ -Wall -Wextra -Werror -std=c++98

SRC		= phonebook.cpp \
		  contact.cpp \
		  main.cpp

HEADERS	= contact.hpp \
		  phonebook.hpp

OBJ		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
