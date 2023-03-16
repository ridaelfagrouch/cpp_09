#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <exception>
#include <stack>
#include <cstdlib>

class RPN
{
    private:
        std::stack<double> Stack;
        std::string str;
        char *end;
        double value1;
        double value2;
        
    public:
        bool isOperator(char c);
        void checkNumber(std::string input, size_t &i);

        RPN(std::string input);
        ~RPN(void);
        RPN(const RPN &other);
        RPN &operator=(const RPN &rhs);
};