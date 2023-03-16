CFILES = main.cpp PmergeMe.cpp
OFILES = ${CFILES:.cpp=.opp}

CXX = c++
HEADER = PmergeMe.cpp.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address 
NAME = PmergeMe.cpp

all : ${OFILES}
	@${CXX} ${CXXFLAGS} ${CFILES} -o ${NAME}

%.opp:%.cpp ${HEADER}
	@${CXX} ${CXXFLAGS} -o $@ -c $<

clean:
	@rm -f ${OFILES}

fclean : clean
	@rm -f ${NAME}

re : fclean all