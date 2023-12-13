/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.cpp                                        |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/24 14:47:46 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 13/12/2023 04:42:22 PM safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cassert>
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		throw std::invalid_argument("Invalid number of arguments");
	try
	{
		std::cout << "Result: " << RPN::calculateRPN(argv[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
