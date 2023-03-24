#include "BitcoinExchange.hpp"

void BitcoinExchange::storDataBase(void)
{
    std::ifstream fileStream;
    std::string line;

    fileStream.open("data.csv");
    if (fileStream.is_open())
    {
        if (getline(fileStream, line))
        {
            line.clear();
            while (getline(fileStream, line))
            {
                trim(line, ' ');
                if (line.size() == 0)
                    continue;
                std::stringstream str(line);
                getline(str, tmp1, ',');
                trim(tmp1, ' ');
                getline(str, tmp2, ',');
                trim(tmp2, ' ');
                dataBase.insert(std::pair<std::string, std::string>(tmp1, tmp2));
                tmp1.clear();
                tmp2.clear();
                line.clear();
                str.clear();
            }
        }
        else
            throw std::string("Error: file dataBase is empty.");
    }
    else
        throw std::string("Error: could not open file.");
}

//-----------------------------------------------------------------------

int BitcoinExchange::checkFile(std::string file)
{
    std::stringstream ss(file);

    std::string line;
    getline(ss, line, '.');
    getline(ss, line, '.');
    if (line == "txt")
        return (ss.clear(), line.clear(), 1);
    return (ss.clear(), line.clear(), 0);
}

//-----------------------------------------------------------------------

void BitcoinExchange::trim(std::string &s, char c)
{
    std::string str;
    size_t index = s.find_first_not_of(c);
    if (index != std::string::npos)
        str += s.substr(index);
    index = str.find_last_not_of(c);
    if (index != std::string::npos)
    {
        str = str.substr(0, index + 1);
    }
    s = str;
}

//-----------------------------------------------------------------------

bool isNumber(std::string str)
{
    char c;
    int count = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        c = str[i];
        if (c == '.' || (c == '-' && i == 0))
        {
            count++;
            if (count > 1)
                return false;
            continue;
        }
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

//-----------------------------------------------------------------------

int BitcoinExchange::parseDate(std::string date)
{
    std::stringstream ss(date);
    count = 0;
    while (getline(ss, temp, '-'))
    {
        if (count == 0 && !(isNumber(temp) && temp.length() == 4))
            return (temp.clear(), ss.clear(), -1);
        if (count == 1 && !(isNumber(temp) && temp.length() == 2 && atoi(temp.c_str()) > 0 && atoi(temp.c_str()) < 13))
            return (temp.clear(), ss.clear(), -1);
        if (count == 2 && !(isNumber(temp) && temp.length() == 2 && atoi(temp.c_str()) > 0 && atoi(temp.c_str()) <= 31))
            return (temp.clear(), ss.clear(), -1);
        count++;
    }
    if (count == 3 && date[date.length() - 1] != '-')
        return (ss.clear(), 1);
    return (ss.clear(), -1);
}

//-----------------------------------------------------------------------

int BitcoinExchange::parseValue(std::string value)
{
    char *end;
    std::stringstream ss(value);
    if (!isNumber(value))
        return (ss.clear(), -1);
    else if (strtod(value.c_str(), &end) > 1000)
        return (ss.clear(), -2);
    else if (atoi(value.c_str()) < 0)
        return (ss.clear(), -3);
    return (1);
}

//-----------------------------------------------------------------------

void BitcoinExchange::outputData(std::string &line)
{
    std::stringstream str(line);
    getline(str, tmp1, '|');
    trim(tmp1, ' ');
    tmp1.size() > 0 ? check1 = parseDate(tmp1) : throw std::string("bad input");
    getline(str, tmp2, '|');
    trim(tmp2, ' ');
    str.clear();
    tmp2.size() > 0 ? check2 = parseValue(tmp2) : throw std::string("bad input");
    if (check1 == 1 && check2 == 1)
    {
        char *end;
        std::map<std::string, std::string>::iterator it = dataBase.lower_bound(tmp1.c_str());
        if (it->first != tmp1 && it != dataBase.begin())
            it--;
        std::cout << tmp1 << " => " << tmp2 + " = " << strtod(it->second.c_str(), &end) * strtod(tmp2.c_str(), &end) << std::endl;
        tmp1.clear();
        tmp2.clear();
    }
    if (check1 == -1 || check2 == -1)
        throw std::string("bad input");
    if (check2 == -2)
        throw std::string("too large a number.");
    if (check2 == -3)
        throw std::string("not a positive number.");
}

//-----------------------------------------------------------------------

void BitcoinExchange::processLine(std::string line)
{
    std::stringstream ss(line);

    count = 0;
    while (getline(ss, temp, '|'))
    {
        count++;
        temp.clear();
    }
    ss.clear();
    try
    {
        if (line[line.length() - 1] == '|')
            throw std::string("bad input");
        count == 2 ? outputData(line) : throw std::string("bad input");
    }
    catch (std::string err)
    {
        if (err == "bad input")
        {
            std::string ptr = "Error: ";
            ptr.append(err).append(" => ").append(line);
            std::cout << ptr << std::endl;
            ptr.clear();
        }
        else if (err == "too large a number." || err == "not a positive number.")
            std::cout << "Error: " + err << std::endl;
    }
}

//-----------------------------------------------------------------------

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream fileStream;
    std::string line;

    storDataBase();
    if (dataBase.size() == 0)
        throw std::string("Error: no data in database.");
    if (checkFile(file))
    {
        fileStream.open(file.c_str());
        if (fileStream.is_open())
        {
            if (getline(fileStream, line))
            {
                while (getline(fileStream, line))
                {
                    if (line.size() == 0)
                        continue;
                    trim(line, ' ');
                    processLine(line);
                    line.clear();
                }
            }
            else
                throw std::string("Error: empty file.");
        }
        else
            throw std::string("Error: could not open file.");
    }
    else
        throw std::string("Error: invalid file.");

    fileStream.close();
}

//-----------------------------------------------------------------------

BitcoinExchange::~BitcoinExchange()
{
    dataBase.clear();
}