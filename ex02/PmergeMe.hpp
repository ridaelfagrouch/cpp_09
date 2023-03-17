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
#include <deque>
#include <ctime> 

class PmergeMe
{
    private:
        std::vector<int> insertSortVector;
        std::deque<int> insertSortDeque;
        std::string input;

        clock_t startTimeV;
        clock_t endTimeV;
        clock_t startTimeD;
        clock_t endTimeD;
        
    public:
        void sortAlgoV(std::string str);
        void sortAlgoD(std::string str);
        
        PmergeMe(std::string str);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &rhs);
};