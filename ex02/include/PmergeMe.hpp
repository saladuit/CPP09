/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  PmergeMe.hpp                                    |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 14/12/2023 02:06:36 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 27/03/2024 15:18:46 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

namespace pmergeme
{
	template <typename T>
	void sortPair(T &a, T &b)
	{
		if (a > b)
			std::swap(a, b);
	}

	template <typename T>
	void mergePairs(T &a1, T &b1, T &a2, T &b2)
	{
		sortPair(a1, b1);
		sortPair(a2, b2);
		if (a1 > a2)
		{
			std::swap(a1, a2);
			std::swap(b1, b2);
		}
	};

	template <typename Container>
	void recursion(Container &args, size_t first, size_t last, size_t step)
	{
		auto size = last - first;
		if (size < 2)
			return;
		bool has_stray = (size % 2 != 0);
		auto end = has_stray ? last - 1 : last;
		for (size_t i = first; i < end; i += step)
		{
			swap_if_greater(args[i], args[i + step]);
		}
	};

	template <typename Container, typename T>
	void merge_insertion_sort(Container &args)
	{
		size_t size = args.size();
		std::list<T> main_chain;
		recursion(args, 0, size - 1, 1);
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
