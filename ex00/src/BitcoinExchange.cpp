
/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   BitcoinExchange.cpp                             |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/24 14:47:46 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2023/05/24 14:47:46 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(std::string file_name)
	: _file(file_name.c_str()), _data("data.csv"), _dates_and_prices()
{
	if (!_file.is_open())
		throw std::runtime_error("File could not be opened.");
	if (!_data.is_open())
		throw std::runtime_error("Data base is missing");
}

void BitcoinExchange::run()
{
	std::string line;
	std::getline(_data, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Data base is corrupt.");
	while (!_data.eof())
	{
		try
		{
			std::getline(_data, line);
			if (line.empty())
				continue;
			parseDataBase(line);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	/* for (auto &it : _dates_and_prices) */
	/* { */
	/* 	try */
	/* 	{ */
	/* std::cout << std::setprecision(2) */
	/* 		  << std::setiosflags(std::ios::fixed) << it.first << " => " */
	/* 		  << it.second << std::endl; */
	/* 	} */
	/* 	catch (std::exception &e) */
	/* 	{ */
	/* 		std::cout << "Error: " << e.what() << std::endl; */
	/* 	} */
	/* } */
	std::getline(_file, line);
	if (line != "date | value")
		throw std::runtime_error("Input file doesn't contain correct header.");
	while (_file.eof() == false)
	{
		try
		{
			std::getline(_file, line);
			if (line.empty())
				continue;
			std::pair<Date, double> date_and_quantity = parseInputLine(line);
			printResult(date_and_quantity.first.toString(),
						date_and_quantity.second);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::printResult(std::string date, double quantity) const
{
	double current_price = 0;

	if (quantity < 0)
		throw std::runtime_error("Quantity not positive => " +
								 std::to_string(quantity));
	if (quantity > 1000)
		throw std::runtime_error("Quantity out of range => " +
								 std::to_string(quantity));
	if (_dates_and_prices.find(Date(date)) == _dates_and_prices.end())
		current_price = _dates_and_prices.lower_bound(Date(date))->second;
	else
		current_price = _dates_and_prices.at(Date(date));
	std::cout << std::setprecision(2) << std::setiosflags(std::ios::fixed)
			  << date << " => " << quantity << " = " << quantity * current_price
			  << std::endl;
}

void BitcoinExchange::parseDataBase(const std::string &line)
{
	size_t pos = line.find(",");
	std::string date = line.substr(0, pos);
	double price = std::stod(line.substr(pos + 1));
	_dates_and_prices.insert(std::make_pair(Date(date), price));
}

std::pair<Date, double> BitcoinExchange::parseInputLine(const std::string &line)
{
	std::istringstream iss(line);
	std::string date;
	std::string delimiter;
	double quantity;
	std::string rest_of_line;
	iss >> date;
	iss >> delimiter;
	if (delimiter != "|")
		throw std::runtime_error("No delimiter for: " + line);
	iss >> quantity;
	iss >> rest_of_line;
	if (rest_of_line.size() > 0)
		throw std::runtime_error("Extra input => " + rest_of_line);
	return (std::make_pair(date, quantity));
}

BitcoinExchange::~BitcoinExchange()
{
}
