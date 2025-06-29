NAME    := zoo

CXX     := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++20

SRCS    := main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS    := $(SRCS:.cpp=.o)
HEADERS := Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all
