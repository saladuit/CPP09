/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   main.cpp                                        |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2023/05/24 14:47:46 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2023/05/24 14:47:46 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin [file_name]" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		BitcoinExchange exchange(argv[1]);
		exchange.log();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
