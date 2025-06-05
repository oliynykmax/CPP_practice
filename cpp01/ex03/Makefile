NAME    := violence

CXX     := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++20

SRCS    := main.cpp HumanA.cpp HumanB.cpp Weapon.cpp 
OBJS    := $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
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
