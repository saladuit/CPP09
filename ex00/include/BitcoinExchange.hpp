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
	void log();
	void parseDataBase();
	void validateInput(const std::string &line);

  private:
	std::fstream _file;
	std::fstream _data;
	std::set<std::string, int> _dates_and_prices;
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
