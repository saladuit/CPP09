/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  RPN.cpp                                         |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 13/12/2023 03:47:08 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 13/12/2023 04:46:42 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::calculateRPN(const std::string &expression)
{
	std::stringstream ss(expression);
	std::stack<int> stack;

	if (expression.empty())
		throw std::invalid_argument("Empty expression");
	if (expression.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("Invalid expression");
	for (std::string token; ss >> token;)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::invalid_argument("Invalid expression");
			int right = stack.top();
			stack.pop();
			int left = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(left + right);
			else if (token == "-")
				stack.push(left - right);
			else if (token == "*")
				stack.push(left * right);
			else if (token == "/")
			{
				if (right == 0)
					throw std::invalid_argument("Invalid expression");
				stack.push(left / right);
			}
		}
		else if (std::isdigit(token[0]))
		{
			if (token.size() > 1)
				throw std::invalid_argument("Invalid expression");
			stack.push(std::stoi(token));
		}
		else
			throw std::invalid_argument("Invalid expression");
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Invalid expression");
	return (stack.top());
}
/* ************************************************************************** */
