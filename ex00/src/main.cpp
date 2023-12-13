/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  main.cpp                                        |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 13/12/2023 12:41:50 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 13/12/2023 12:42:04 PM by safoh     \___)=(___/                  */
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
		exchange.run();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
