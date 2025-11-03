NAME	= harl
CC		= c++ -Wall -Wextra -Werror -std=c++98 -MMD

SRC		= main.cpp \
		  Harl.cpp

HEADERS	= Harl.hpp
OBJ		= $(SRCS:.cpp=.o)
DEPS	= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ) $(DEPS) $(NAME).d

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
