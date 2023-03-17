#include "PmergeMe.hpp"

bool isNumber(std::string str)
{
	char c;
    for (int i = 0; i < (int)str.length() ; i++) {
		c = str[i];
        if (std::isdigit(c) == 0) 
            return false;
    }
    return true;
}

//-----------------------------------------------------------------------


void PmergeMe::sortAlgoD(std::string str)
{
    // std::deque data management

    startTimeD = std::clock();
    int key;
    std::stringstream ptr(str);
    std::string tmp;

    while(std::getline(ptr, tmp, ' '))
    {
        if (isNumber(tmp))
            insertSortDeque.push_back(atoi(tmp.c_str()));
        else
            throw std::string("Error");
        tmp.clear();
    }
    input = str;

    // std::deque sorting

    for (int i = 1; i < (int)insertSortDeque.size(); i++)
    {
        key = insertSortDeque.at(i);
        int j = i - 1;
        for (;j >= 0 && insertSortDeque.at(j) > key; j--)
            insertSortDeque.at(j+1) = insertSortDeque.at(j);
        insertSortDeque.at(j+1) = key;
    }
    endTimeD = std::clock() - startTimeD;

    std::cout << "Time to process a range of " << insertSortDeque.size() << " elements with std::deque : " << (float)endTimeD/1000 << " us" << std::endl;
}

//-----------------------------------------------------------------------

void PmergeMe::sortAlgoV(std::string str)
{
    // std::vector data management

    startTimeV = std::clock();
    int key;
    std::stringstream ptr(str);
    std::string tmp;

    while(std::getline(ptr, tmp, ' '))
    {
        if (isNumber(tmp))
            insertSortVector.push_back(atoi(tmp.c_str()));
        else
            throw std::string("Error");
        tmp.clear();
    }
    input = str;

    // std::vector sorting

    for (int i = 1; i < (int)insertSortVector.size(); i++)
    {
        key = insertSortVector[i];
        int j = i - 1;
        for (;j >= 0 && insertSortVector[j] > key; j--)
            insertSortVector[j + 1] = insertSortVector[j];
        insertSortVector[j + 1] = key;
    }

    endTimeV = std::clock() - startTimeV;

    std::cout << "Before:  " << input << std::endl;
    std::cout << "After:   ";
    std::vector<int>::iterator it = insertSortVector.begin();
    for(; it != insertSortVector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << insertSortVector.size() << " elements with std::vector : " << (float)endTimeV/1000 << " us" << std::endl;
}

//-----------------------------------------------------------------------

PmergeMe::PmergeMe(std::string str)
{
    sortAlgoV(str);
    sortAlgoD(str);
}

//-----------------------------------------------------------------------

PmergeMe::~PmergeMe()
{
    insertSortVector.clear();
}