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
#include "Subset.hpp"

namespace pmergeme
{
template <typename Container>
void insertion_sort(Container &args)
{
	Subset<Container> subset(args);
	subset.merge_insertion_sort();
	// with class nsubset and slice class
	std::cout << "After sorting:";
	for (auto &arg : args)
	{
		std::cout << " " << arg;
	}
	std::cout << std::endl;
};
}; // namespace pmergeme

#endif
/* ************************************************************************** */
