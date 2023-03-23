CFILES = main.cpp RPN.cpp
OFILES = ${CFILES:.cpp=.opp}

CXX = c++
HEADER = RPN.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = RPN

all : ${OFILES}
	@${CXX} ${CXXFLAGS} ${CFILES} -o ${NAME}

%.opp:%.cpp ${HEADER}
	@${CXX} ${CXXFLAGS} -o $@ -c $<

clean:
	@rm -f ${OFILES}

fclean : clean
	@rm -f ${NAME}

re : fclean all