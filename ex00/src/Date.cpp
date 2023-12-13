/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  Date.cpp                                        |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 13/12/2023 12:42:53 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 13/12/2023 02:13:05 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date()
{
}

Date::Date(const std::string &date) : _tm(this->parseDate(date))
{
	this->_tm = this->parseDate(date);
}

Date::Date(const Date &other) : _tm(other._tm)
{
}

Date &Date::operator=(const Date &rhs)
{
	if (this != &rhs)
		this->_tm = rhs._tm;
	return (*this);
}

Date::~Date()
{
}

std::string Date::toString() const
{
	std::stringstream ss;
	ss << this->_tm.tm_year + 1900 << "-";
	if (this->_tm.tm_mon < 10)
		ss << "0";
	ss << this->_tm.tm_mon + 1 << "-";
	if (this->_tm.tm_mday < 10)
		ss << "0";
	ss << this->_tm.tm_mday;
	return (ss.str());
}

struct tm Date::getTm() const
{
	return (this->_tm);
}

bool Date::operator==(const Date &rhs) const
{
	return (getTm().tm_year == rhs.getTm().tm_year &&
			getTm().tm_mon == rhs.getTm().tm_mon &&
			getTm().tm_mday == rhs.getTm().tm_mday);
}

bool Date::operator<(const Date &rhs) const
{
	if (getTm().tm_year != rhs.getTm().tm_year)
		return (getTm().tm_year < rhs.getTm().tm_year);
	if (getTm().tm_mon != rhs.getTm().tm_mon)
		return (getTm().tm_mon < rhs.getTm().tm_mon);
	return (getTm().tm_mday < rhs.getTm().tm_mday);
}

bool Date::operator>(const Date &rhs) const
{
	if (getTm().tm_year != rhs.getTm().tm_year)
		return (getTm().tm_year > rhs.getTm().tm_year);
	if (getTm().tm_mon != rhs.getTm().tm_mon)
		return (getTm().tm_mon > rhs.getTm().tm_mon);
	return (getTm().tm_mday > rhs.getTm().tm_mday);
}

struct tm Date::parseDate(const std::string &date)
{
	struct tm tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		throw std::runtime_error("Date format incorrect => " + date + ".");
	return (tm);
}

std::ostream &operator<<(std::ostream &ostream, const Date &date)
{
	ostream << date.toString();
	return (ostream);
}
