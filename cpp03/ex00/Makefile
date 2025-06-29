NAME    := ClapTrap

CXX     := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++20

SRCS    := main.cpp ClapTrap.cpp
OBJS    := $(SRCS:.cpp=.o)
HEADERS := ClapTrap.hpp

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
