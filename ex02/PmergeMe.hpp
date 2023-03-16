#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <exception>
#include <vector>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> insertSort;
        long int startTime;
        
    public:
        PmergeMe(std::string input);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &rhs);
};