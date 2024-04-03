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
	template <typename Container>
	void recursion(Container &args, size_t first, size_t last)
	{
		size_t size = last - first;
		static size_t original_size = 0;

		if (size < 2)
			return;
		bool has_stray = (size % 2 != 0);
		size_t end = has_stray ? last - 1 : last;
		size_t end_b = end;
		size_t start_a = first;
		size_t start_b = (end_b - first) / 2 + start_a;
		size_t end_a = start_b;
		size_t group_size = end_a - start_a;
		if (original_size == 0)
			original_size = group_size * 2;
		for (size_t i = 0; i < group_size; i += (first) ? 2 : 1)
		{
			if (args[start_a + i] > args[start_b + i])
			{
				std::swap(args[start_a + i], args[start_b + i]);
				if (first && group_size > 1)
				{
					std::swap(args[start_a + i + 1], args[start_b + i + 1]);
				}
			}
		}
		recursion(args, start_b, end_b);
	};

	template <typename Container>
	void merge_insertion_sort(Container &args)
	{
		size_t size = args.size();
		recursion(args, 0, size);
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

/*
 * 0. 5231476
 * 1. 52 31 47    6
 * 2. 25 13 47    6
 *    ab ab ab    b
 * 3.1 25 13   47
 * 3.2 25 14   47
 *     a  b    b     -
 * 3.3 -
 * 3.4 13
 *     25 47
 *     47 25 13
 * 4. 4 2 1
 *    7 5 3 6
 *
 * 1. Group into pairs
 * 2. Sort pair elements
 * 3. Recurse
 * 3.1 Group into pairs
 * 3.2 Sort pair elements
 * 3.3 Recurse
 * 3.3.1 Group into pairs
 * ...
 * 3.4 Jacobsthal
 * 4. Jacobsthal
 */
