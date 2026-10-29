
#include <cctype>
#include <climits>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <ctime>
#include <map>
#include <stdio.h>
#include <locale.h>
#include <time.h>

#include "BitcoinExchange.hpp"
#include "def.hpp"


BitcoinExchange::BitcoinExchange()	{}

BitcoinExchange::BitcoinExchange(std::string pathToInputFile,
		char sep_in, std::string pathToDataFile, char sep_data)
{

	if (pathToInputFile.empty())
		throw BitcoinExchange::FileLoadingException();
	if (pathToDataFile.empty())
		throw BitcoinExchange::FileLoadingException();

	this->_dataIf.open(pathToDataFile.c_str());
	if (!this->_dataIf.is_open())
		throw BitcoinExchange::FileLoadingException();

	this->_inputIf.open(pathToInputFile.c_str());
	if (!this->_inputIf.is_open())
		throw BitcoinExchange::FileLoadingException();

	this->_dataSep = sep_data;
	this->_dataPath = pathToDataFile;
	this->_inputSep = sep_in;
	this->_inputPath = pathToInputFile;

	this->load_data();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) :
	_dataSep(other._dataSep), _inputSep(other._inputSep)
{
	this->_dataIf.open(other._dataPath.c_str());
	if (!this->_dataIf.is_open())
		throw BitcoinExchange::FileLoadingException();

	this->_inputIf.open(other._inputPath.c_str());
	if (!this->_inputIf.is_open())
		throw BitcoinExchange::FileLoadingException();

	this->_dataPath = other._dataPath;
	this->_inputPath = other._inputPath;

	std::map<long,float>::iterator tmp;
	tmp = this->_data.find('k');
	for (; tmp != other._data.end(); tmp++)
		this->_data.insert(std::make_pair(tmp->first, tmp->second));
}

BitcoinExchange::~BitcoinExchange()
{
	if (_dataIf.is_open())
		_dataIf.close();
	if (_inputIf.is_open())
		_inputIf.close();
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->~BitcoinExchange();
		new (this) BitcoinExchange(other);
	}
	return (*this);
}


void	BitcoinExchange::load_data()
{
	if (!this->_dataIf.is_open())
		throw BitcoinExchange::FileLoadingException();

	this->_data = this->createMapData(this->_dataIf, this->_dataSep);
}

float	BitcoinExchange::exchangeRate(std::string &date, float qty)
{
	if (date.empty())
		return -3;

	long int t = string2timestamp(date);

	if (qty > 0 && qty <= LIMIT_BTC && t > 0)
	{
		std::map<long,float>::iterator tmp;
		tmp = this->_data.lower_bound(t);

		if (this->_data.empty()) return -4;

		else if (tmp != this->_data.end())
		{
			if (tmp->first != t && tmp != this->_data.begin())
				tmp--;
		}
		else
			tmp--;
		return (qty * tmp->second);
	}

	int tpm = 0;

	if (qty < 0)
		tpm = -1;
	if (qty > LIMIT_BTC)
		tpm = -2;
	if (t <= 0)
		tpm = -3;
	return (static_cast<float>(tpm));
}

void	BitcoinExchange::exec_file()
{
	if (!this->_inputIf.is_open())
		throw BitcoinExchange::FileLoadingException();

	std::string	line;
	bool		firstLine = true;

	while (std::getline(this->_inputIf, line))
	{
		if (firstLine && std::isalpha(line[0]))
			continue ;
		firstLine = false;
		size_t sep_pos = line.find(this->_inputSep);
		if (sep_pos == std::string::npos || line.find('-') == std::string::npos) 
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue;
		}

		std::string date_str = line.substr(0, sep_pos - 1);
		std::string value_str = line.substr(sep_pos + 2);

		if (value_str.empty())
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue ;
		}

		char *endptr = 0;
		float qty = std::strtof(value_str.c_str(), &endptr);
		float out = exchangeRate(date_str, qty);

		switch ((int)out) {
			case -1:
				std::cout << "Error: not a positive number.\n";
				break ;
			case -2:
				std::cout << "Error: too large a number.\n";
				break ;
			case -3:
				std::cout << "Error: bad input => " << line << "\n";
				break ;
			case -4:
				std::cout << "Error: Something wrong with the map => " << "\n";
				break ;
			default:
				std::cout << date_str << " => " << qty << " => " << out << '\n';
		}
	}
}

std::map<long, float>	BitcoinExchange::get_dataMap()	{	return (_data);	}

const char *BitcoinExchange::FileLoadingException::what() const throw()
{
	return (RED "Something wrong with the file \ncheck input file and Data file" RESET);
}


long int	string2timestamp(const std::string &str)
{
    struct tm tm ;

	memset(&tm, 0, sizeof(struct tm));

    if(strptime(str.c_str(), "%04Y-%02m-%02d",&tm) == NULL)
          return -1;
    return (mktime(&tm));
}


float	BitcoinExchange::exchangeRate(std::map<long int, float> dataM,
									std::string &date, float qty)
{
	if (date.empty())
		return -4;

	long int t = string2timestamp(date);
	int tpm = -1;

	if (qty > 0 && (long)qty <= INT_MAX && t > 0)
	{
		std::map<long,float>::iterator tmp;
		tmp = dataM.lower_bound(t);

		if (dataM.empty()) return -1;

		else if (tmp != dataM.end())
		{
			if (tmp->first != t && tmp != dataM.begin())
				tmp--;
		}
		else
			tmp--;
		return (qty * tmp->second);
	}

	if (qty < 0)
		tpm = -1;
	if ((long)qty > INT_MAX)
		tpm = -2;
	if (t <= 0)
		tpm = -3;
	return (static_cast<float>(tpm));
}

std::map<long, float>	BitcoinExchange::createMapData(std::ifstream &in,
													char sep)
{
	std::string line;
	std::map<long, float> m;
	std::getline(in, line);
	while (std::getline(in, line)) {
		size_t sep_pos = line.find(sep);
		if (sep_pos == std::string::npos || line.find('-') == std::string::npos)
		{
			std::cerr << "Error data: Bad input =>" << line << '\n';
			continue;
		}

		std::string date_str = line.substr(0, sep_pos);
		std::string value_str = line.substr(sep_pos + 1);


		value_str.erase(0, value_str.find_first_not_of(" \t"));
		value_str.erase(value_str.find_last_not_of(" \t") + 1);

		date_str.erase(0, date_str.find_first_not_of(" \t"));
		date_str.erase(date_str.find_last_not_of(" \t") + 1);

		char* endptr = 0;
		float value = std::strtof(value_str.c_str(), &endptr);

		if (endptr == value_str.c_str() || *endptr != '\0')
			continue;
		long timestamp = string2timestamp(date_str);
		if (timestamp <= 0)
		{
			std::cerr << "Error: Bad input => " << line << '\n';
			continue;
		}

		m.insert(std::make_pair(timestamp, value));
	}
	return (m);
}
