
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

void BitcoinExchange::run()
{
	std::string line;
	std::getline(_file, line);
	while (std::getline(_file, line))
	{
		try
		{
			validateInput(line);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	std::getline(_data, line);
	while (std::getline(_data, line))
	{
		try
		{
			parseDataBase(line);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	for (auto &it : _dates_and_quantities)
	{
		try
		{

			printResult(it.first, it.second);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}
void BitcoinExchange::printResult(std::string date, double quantity) const
{

	struct tm tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		throw std::runtime_error("Date format incorrect => " + date + ".");
	if (quantity < 0)
		throw std::runtime_error("Quantity not positive => " +
								 std::to_string(quantity));
	if (quantity > 1000)
		throw std::runtime_error("Quantity out of range => " +
								 std::to_string(quantity));
	std::cout << date << " => " << quantity << " = "
			  << quantity * _dates_and_prices.at(date) << std::endl;
}
void BitcoinExchange::parseDataBase(const std::string &line)
{
	size_t pos = line.find(",");
	std::string date = line.substr(0, pos);
	double price = std::stod(line.substr(pos + 1));
	_dates_and_prices.insert(std::make_pair(date, price));
	/* std::cout << date << " " << price << std::endl; */
}

void BitcoinExchange::validateInput(const std::string &line)
{
	std::istringstream iss(line);
	std::string date;
	std::string delimiter;
	double quantity;
	std::string rest_of_line;
	iss >> date;
	iss >> delimiter;
	if (delimiter != "|")
		throw std::runtime_error("No delimiter => " + delimiter + ".");
	iss >> quantity;
	iss >> rest_of_line;
	if (rest_of_line.size() > 0)
		throw std::runtime_error("Extra input => " + rest_of_line);
	_dates_and_quantities.insert(std::make_pair(date, quantity));
}

BitcoinExchange::~BitcoinExchange()
{
}
