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

long int getTimeMs()
{
	struct timeval tp;
	
	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000000 + tp.tv_usec);
}

//-----------------------------------------------------------------------

PmergeMe::PmergeMe(std::string input)
{
    std::stringstream str(input);
    std::string tmp;

    while(std::getline(str, tmp, ' '))
    {
        if (isNumber(tmp))
            insertSort.push_back(atoi(tmp.c_str()));
        else
            throw std::string("Error");
        tmp.clear();
    }

    startTime = getTimeMs();
    int key;
    for (int i = 1; i < (int)insertSort.size(); i++)
    {
        key = insertSort[i];
        int j = i - 1;
        for (;j >= 0 && insertSort[j] > key; j--)
            insertSort[j + 1] = insertSort[j];
        insertSort[j + 1] = key;
    }

    std::cout << "Before:  " << input << std::endl;
    std::cout << "After:   ";
    std::vector<int>::iterator it = insertSort.begin();
    for(; it != insertSort.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of 5 elements with std::[..] : " << getTimeMs() - startTime << " us" << std::endl;
}

//-----------------------------------------------------------------------

PmergeMe::~PmergeMe()
{
    insertSort.clear();
}