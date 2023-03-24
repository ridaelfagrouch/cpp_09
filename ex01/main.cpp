
#include "RPN.hpp"


int main(int ac, char **av)
{
	try
    {
        if (ac != 2)
            throw std::string("Error: invalid number of arguments.");
        std::string str(av[1]);
        RPN rpn(str);
    }
    catch(std::string err)
    {
        std::cout << err << '\n';
    }
	return 0;
}