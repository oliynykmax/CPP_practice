NAME    := my_awesome_phonebook

CXX     := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++20

SRCS    := main.cpp PhoneBook.cpp Contact.cpp
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

