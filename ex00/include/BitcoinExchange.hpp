/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:26:52 by safoh             #+#    #+#             */
/*   Updated: 13/12/2023 02:26:22 PM safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <fstream>
#include <map>
#include <set>
#include <string>

#include "Date.hpp"

class BitcoinExchange
{
  public:
	BitcoinExchange(std::string file_name);
	~BitcoinExchange();
	void run();
	void parseDataBase(const std::string &line);
	std::pair<Date, double> parseInputLine(const std::string &line);
	void printResult(std::string date, double quantity) const;
	void printPrices(const std::string &line) const;

  private:
	std::fstream _file;
	std::fstream _data;
	std::map<Date, double> _dates_and_prices;
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);
};

/* **************************Private_member_functions************************ */

/* **************************Public_member_functions************************* */

/* *******************************Constructors******************************* */

/* ********************************Overloads********************************* */

#endif
/* ************************************************************************** */
