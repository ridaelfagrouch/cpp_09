CFILES = main.cpp BitcoinExchange.cpp
OFILES = ${CFILES:.cpp=.opp}

CXX = c++
HEADER = BitcoinExchange.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = btc

all : ${OFILES}
	@${CXX} ${CXXFLAGS} ${CFILES} -o ${NAME}

%.opp:%.cpp ${HEADER}
	@${CXX} ${CXXFLAGS} -o $@ -c $<

clean:
	@rm -f ${OFILES} 

fclean : clean
	@rm -f ${NAME}

re : fclean all