#ifndef DATE_HPP
#define DATE_HPP

#include <bits/types/struct_tm.h>
#include <string>

class Date
{
  public:
	Date(const std::string &date);
	Date(const Date &other);
	Date &operator=(const Date &rhs);
	~Date();

	bool operator==(const Date &rhs) const;
	bool operator<(const Date &rhs) const;
	bool operator>(const Date &rhs) const;

	std::string toString() const;

  private:
	Date();
	struct tm tm;
};

std::ostream &operator<<(std::ostream &ostream, const Date &date);

#endif