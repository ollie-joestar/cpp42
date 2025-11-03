NAME	=	ex01
CC 		=	c++ -Wall -Wextra -Werror -std=c++98 -MMD

SRCS	=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \

OBJS	=	$(SRCS:.cpp=.o)
DEPS	=	$(SRCS:.cpp=.d)
HEADERS	=	ClapTrap.hpp ScavTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CC) -c $< -o $@

clean:
	@rm -f $(OBJS) $(DEPS) $(NAME).d

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
