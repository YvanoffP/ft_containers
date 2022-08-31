SRCS			= ./inc/tests.cpp

OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++ #g++-11
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -pedantic -g -I.
CPP_FLAGS       = -std=c++98

NAME			= containers

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(CPP_FLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re testR
