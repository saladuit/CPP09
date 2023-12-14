/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  PmergeMe.hpp                                    |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 14/12/2023 02:06:36 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 14/12/2023 02:15:50 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

namespace PMERGEME_HPP
{
void pmergeme(std::vector<std::string> &args)
{
	std::sort(args.begin(), args.end());
	for (auto &arg : args)
	{
		std::cout << arg << std::endl;
	}
}
}; // namespace PMERGEME_HPP

#endif
/* ************************************************************************** */
