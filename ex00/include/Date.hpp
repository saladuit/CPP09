#ifndef DATE_HPP
#define DATE_HPP

#include <bits/types/struct_tm.h>
#include <iostream>
#include <sstream>
#include <string>

class Date
{
  public:
	Date();
	Date(const std::string &date);
	Date(const Date &other);
	Date &operator=(const Date &rhs);
	~Date();

	bool operator==(const Date &rhs) const;
	bool operator<(const Date &rhs) const;
	bool operator>(const Date &rhs) const;

	std::string toString() const;
	struct tm parseDate(const std::string &date);
	struct tm getTm() const;

  private:
	struct tm _tm;
};

std::ostream &operator<<(std::ostream &ostream, const Date &date);

#endif
