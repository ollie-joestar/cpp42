NAME	=	ex00
CXX 	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -MMD

SRCS	=	main.cpp \
			ScalarConverter.cpp

OBJS	=	$(SRCS:.cpp=.o)
DEPS	=	$(SRCS:.cpp=.d)
HEADERS	=	ScalarConverter.hpp

RESET	=	\033[0m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) compiled successfully!$(RESET)"

%.o: %.cpp $(HEADERS)
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(DEPS) $(NAME).d
	@echo "$(YELLOW)Object files and dependencies removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Executable $(NAME) removed!$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re test
