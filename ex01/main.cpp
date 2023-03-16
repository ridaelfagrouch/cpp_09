
#include "RPN.hpp"


int main(int ac, char **av)
{
	try
    {
        if (ac != 2)
            throw std::string("Error: invalid number of arguments.");
        RPN rpn(std::string(av[1]));
    }
    catch(std::string err)
    {
        std::cout << err << '\n';
    }
	return 0;
}