/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:26:52 by safoh             #+#    #+#             */
/*   Updated: 2023/08/05 15:55:25 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <fstream>
#include <map>
#include <set>
#include <string>

class BitcoinExchange
{
  public:
	BitcoinExchange(std::string file_name);
	~BitcoinExchange();
	void run();
	void parseDataBase(const std::string &line);
	void validateInput(const std::string &line);
	void printResult(std::string date, double quantity) const;

  private:
	std::fstream _file;
	std::fstream _data;
	std::map<std::string, double> _dates_and_prices;
	std::map<std::string, double> _dates_and_quantities;
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
