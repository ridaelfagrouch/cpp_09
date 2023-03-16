#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw std::string("Error: invalid number of arguments.");
        BitcoinExchange bitcoin(av[1]);
    }
    catch(std::string err)
    {
        std::cout << err << '\n';
    }
    return (0);
}
