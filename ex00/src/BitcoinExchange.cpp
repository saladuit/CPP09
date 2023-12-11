
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
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(std::string file_name)
	: _file(file_name.c_str()), _data("data.csv")
{
	if (!_file.is_open())
		throw std::runtime_error("File could not be opened.");
	if (!_data.is_open())
		throw std::runtime_error("Data base is missing");
}

void BitcoinExchange::log()
{
	std::string line;
	while (std::getline(_file, line))
	{
		try
		{
			validateInput(line);
			std::cout << line << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	while (std::getline(_data, line))
	{
		/* std::cout << line << std::endl; */
	}
}

void BitcoinExchange::parseDataBase()
{
}
void BitcoinExchange::validateInput(const std::string &line)
{
	std::istringstream iss(line);
	std::string date;
	std::string delimiter;
	int quantity;
	std::string rest_of_line;
	iss >> date >> delimiter >> quantity >> rest_of_line;
	struct tm tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		throw std::runtime_error("Bad input => " + date + ".");
	if (delimiter != "|")
		throw std::runtime_error("Bad input => " + delimiter + ".");
	if (quantity <= 0 || quantity > 1000)
		throw std::runtime_error("Bad input => " + std::to_string(quantity));
	_dates_and_prices.insert(std::make_pair(date, quantity));
}

BitcoinExchange::~BitcoinExchange()
{
}
