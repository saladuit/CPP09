/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.cpp                                        |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/24 14:47:46 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 14/12/2023 02:11:26 PM safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe [digit] [digit] [digit] [...]"
				  << std::endl;
		return (EXIT_FAILURE);
	}
	std::vector<std::string> args(argv + 1, argv + argc);
	for (auto &arg : args)
	{
		std::cout << arg << std::endl;
	}
	pmergeme(args);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
