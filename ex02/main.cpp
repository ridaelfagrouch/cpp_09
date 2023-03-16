#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
    {
        std::string str;
        if (ac == 1)
            throw std::string("Error: invalid number of arguments.");
        int i = 1;
        while(i < ac)
        {
            str += av[i];
            if (i != ac - 1)
                str += " ";
            i++;
        }
        PmergeMe Sort(str);
    }
    catch(std::string err)
    {
        std::cout << err << '\n';
    }
	return 0;
}