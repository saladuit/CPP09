/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  Date.cpp                                        |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 13/12/2023 12:42:53 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 13/12/2023 01:39:14 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date()
{
	std::cout << "Date() called" << std::endl;
}

Date::Date(const std::string &date) : _tm(this->parseDate(date))
{
	std::cout << "Date(const std::string &date) called" << std::endl;
	this->_tm = this->parseDate(date);
}

Date::Date(const Date &other) : _tm(other._tm)
{
	std::cout << "Date(const Date &other) called" << std::endl;
}

Date &Date::operator=(const Date &rhs)
{
	std::cout << "Date &operator=(const Date &rhs) called" << std::endl;
	if (this != &rhs)
		this->_tm = rhs._tm;
	return (*this);
}

Date::~Date()
{
	std::cout << "~Date() called" << std::endl;
}

std::string Date::toString() const
{
	std::cout << "std::string Date::toString() const called" << std::endl;
	std::stringstream ss;
	ss << this->_tm.tm_year + 1900 << "-";
	if (this->_tm.tm_mon < 10)
		ss << "0";
	ss << this->_tm.tm_mon << "-";
	if (this->_tm.tm_mday < 10)
		ss << "0";
	ss << this->_tm.tm_mday;
	return (ss.str());
}

struct tm Date::getTm() const
{
	std::cout << "struct tm Date::getTm() const called" << std::endl;
	return (this->_tm);
}

bool operator==(const Date &lhs, const Date &rhs)
{
	std::cout << "bool operator==(const Date &lhs, const Date &rhs) called"
			  << std::endl;
	return (lhs.getTm().tm_year == rhs.getTm().tm_year &&
			lhs.getTm().tm_mon == rhs.getTm().tm_mon &&
			lhs.getTm().tm_mday == rhs.getTm().tm_mday);
}

bool operator<(const Date &lhs, const Date &rhs)
{
	std::cout << "bool operator<(const Date &lhs, const Date &rhs) called"
			  << std::endl;
	if (lhs.getTm().tm_year != rhs.getTm().tm_year)
		return (lhs.getTm().tm_year < rhs.getTm().tm_year);
	if (lhs.getTm().tm_mon != rhs.getTm().tm_mon)
		return (lhs.getTm().tm_mon < rhs.getTm().tm_mon);
	return (lhs.getTm().tm_mday < rhs.getTm().tm_mday);
}

bool operator>(const Date &lhs, const Date &rhs)
{
	std::cout << "bool operator>(const Date &lhs, const Date &rhs) called"
			  << std::endl;
	if (lhs.getTm().tm_year != rhs.getTm().tm_year)
		return (lhs.getTm().tm_year > rhs.getTm().tm_year);
	if (lhs.getTm().tm_mon != rhs.getTm().tm_mon)
		return (lhs.getTm().tm_mon > rhs.getTm().tm_mon);
	return (lhs.getTm().tm_mday > rhs.getTm().tm_mday);
}

struct tm Date::parseDate(const std::string &date)
{
	struct tm tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		throw std::runtime_error("Date format incorrect => " + date + ".");
	return (tm);
}
