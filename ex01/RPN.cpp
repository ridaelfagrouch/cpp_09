#include "RPN.hpp"

bool RPN::isOperator(char c)
{
    std::string operators = "+-*/";

    for (size_t i = 0; i < operators.length(); i++)
    {
        if (c == operators[i])
            return true;
    }
	return false;
}

//-----------------------------------------------------------------------

void RPN::checkNumber(std::string input, size_t &i)
{
    while (isdigit(input[i]) || input[i] == '.')
		str += input[i++];
    if (strtod(str.c_str(), &end) >= 0 && strtod(str.c_str(), &end) < 10)
        Stack.push(strtod(str.c_str(), &end));
    else
    {
        throw std::string("Error");
    }
	str = "";
}

//-----------------------------------------------------------------------

RPN::RPN(std::string input)
{
	double result;

	for(size_t i = 0; i < input.length() ; i++)
    {
		while (input[i] == ' ')
			i++;
		if (isdigit(input[i]) || input[i] == '.')
            checkNumber(input, i);
		else if (isOperator(input[i]))
        {
            value1 = Stack.top();
            Stack.pop();
            value2 = Stack.top();
            Stack.pop();
			if (input[i] == '+')
				result = value2 + value1;
			else if (input[i] == '-')
				result = value2 - value1;
			else if (input[i] == '*')
				result = value2 * value1;
			else
				result = value2 / value1;
			i++;
			Stack.push(result);
		}
		else
            throw std::string("Error");
	}
	std::cout << Stack.top() << std::endl;
}

RPN::~RPN(void){}