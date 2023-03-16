#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <map>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <exception>
#include <bits/stdc++.h>

class BitcoinExchange
{
    private:
        int count, check1, check2;
        std::string temp, tmp1, tmp2;
        std::map<std::string, std::string> dataBase;

    public:
        int parseDate(std::string date);
        int parseValue(std::string value);

        void trim(std::string &s, char c);

        int checkFile(std::string file);
        void processLine(std::string line);
        void storDataBase(void);
        void outputData(std::string &line);

        BitcoinExchange(std::string file);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
};
