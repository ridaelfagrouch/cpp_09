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

template<typename Container>
void insertionSort(Container &arr, int p, int q) {
    for (int i = p; i < q; i++) {
        int tempVal = arr[i + 1];
        int j = i + 1;
        while (j > p && arr[j - 1] > tempVal) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tempVal;
    }
}

template<typename Container>
void merge(Container& arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template<typename Container>
void sort(Container& arr, int p, int r) {
    if (r - p > 5) {
        int q = (p + r) / 2;
        sort(arr, p, q);
        sort(arr, q + 1, r);
        merge(arr, p, q, r);
    } else {
        insertionSort(arr, p, r);
    }
}

//----------------------------------------------------------------------


void PmergeMe::sortAlgoD(std::string str)
{
    // std::deque data management

    startTimeD = std::clock();
    std::stringstream ptr(str);
    std::string tmp;

    while(std::getline(ptr, tmp, ' '))
    {
        if (isNumber(tmp))
            SortDeque.push_back(atoi(tmp.c_str()));
        else
            throw std::string("Error");
        tmp.clear();
    }
    input = str;

    // std::deque sorting
    sort(SortDeque, 0, SortDeque.size() - 1);

    endTimeD = std::clock() - startTimeD;

    std::cout << "Time to process a range of " << SortDeque.size() << " elements with std::deque : " << (float)endTimeD/1000 << " us" << std::endl;
}

//-----------------------------------------------------------------------

void PmergeMe::sortAlgoV(std::string str)
{
    // std::vector data management

    startTimeV = std::clock();
    std::stringstream ptr(str);
    std::string tmp;

    while(std::getline(ptr, tmp, ' '))
    {
        if (isNumber(tmp))
            SortVector.push_back(atoi(tmp.c_str()));
        else
            throw std::string("Error");
        tmp.clear();
    }
    input = str;

    // std::vector sorting

    sort(SortVector, 0, SortVector.size() - 1);

    endTimeV = std::clock() - startTimeV;

    std::cout << "Before:  " << input << std::endl;
    std::cout << "After:   ";
    std::vector<int>::iterator it = SortVector.begin();
    for(; it != SortVector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << SortVector.size() << " elements with std::vector : " << (float)endTimeV/1000 << " us" << std::endl;
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
    SortVector.clear();
    SortDeque.clear();
}