/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  PmergeMe.hpp                                    |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 14/12/2023 02:06:36 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 15/12/2023 05:03:59 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "Slice.hpp"
namespace pmergeme
{
	namespace utils
	{
		template <typename Container>
		static void tes(){};
	}
	template <typename Container>
	void insertion_sort(Container &args)
	{
		std::sort(args.begin(), args.end());
		std::cout << "After sorting:";
		utils::tes<Container>();
		for (auto &arg : args)
		{
			std::cout << " " << arg;
		}
		std::cout << std::endl;
	};
}; // namespace pmergeme

#endif
/* ************************************************************************** */
