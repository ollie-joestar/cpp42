NAME	=	ex00
CXX 	=	c++ -Wall -Wextra -Werror -std=c++98 -MMD

SRCS	=	main.cpp \
			Bureaucrat.cpp \

OBJS	=	$(SRCS:.cpp=.o)
DEPS	=	$(SRCS:.cpp=.d)
HEADERS	=	Bureaucrat.hpp \

RESET	=	\033[0m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' created successfully!$(RESET)"

%.o: %.cpp $(HEADERS)
	@$(CXX) -c $< -o $@

clean:
	@rm -f $(OBJS) $(DEPS) $(NAME).d
	@echo "$(YELLOW)Cleaned object and dependency files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed executable '$(NAME)'.$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
