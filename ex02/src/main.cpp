/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.cpp                                        |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/24 14:47:46 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 15/12/2023 02:42:23 PM safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>
#include <cstdlib>
#include <deque>
#include <iomanip>

template <typename Container>
Container args_to_container(int argc, char **argv)
{
	Container args;
	std::cout << "Before sorting:";
	for (int i = 1; i < argc; ++i)
	{
		std::cout << " " << argv[i];
		args.push_back(std::atoi(argv[i]));
	}
	std::cout << std::endl;
	return (args);
}

template <typename Container>
void sort_container(int argc, char **argv, const std::string &container_name)
{
	std::chrono::time_point<std::chrono::steady_clock> start =
		std::chrono::steady_clock::now();
	Container numbers = args_to_container<Container>(argc, argv);
	PMergeMe<Container> p_merge_me(numbers);
	p_merge_me.sort();
	std::chrono::time_point<std::chrono::steady_clock> end =
		std::chrono::steady_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << " After sorting:";
	bool sorted = std::is_sorted(numbers.begin(), numbers.end());
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		std::cout << " " << numbers[i];
	}
	if (!sorted)
	{
		std::cerr << " - \x1b[31mError: the container is not sorted\x1b[0m";
	}
	else
	{
		std::cout << " - \x1b[32mThe container is sorted\x1b[0m";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with "
			  << container_name << ": " << std::setiosflags(std::ios::fixed)
			  << diff.count() << " μs" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe [number] [number] [number] [...]"
				  << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		sort_container<std::vector<int>>(argc, argv, "std::vector");
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		sort_container<std::deque<int>>(argc, argv, "std::deque");
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
