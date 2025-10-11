NAME    := btc
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++20 -Iinc
SRCS    := src/main.cpp src/BitcoinExchange.cpp
OBJS    := $(SRCS:src/%.cpp=.build/%.o)
DEPS    := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.build/%.o: src/%.cpp | .build
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

.build:
	mkdir -p .build

clean:
	rm -rf .build

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
