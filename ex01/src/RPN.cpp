/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  RPN.cpp                                         |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 13/12/2023 03:47:08 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 13/12/2023 04:21:41 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::calculateRPN(const std::string &expression)
{
	std::stringstream ss(expression);
	std::stack<int> stack({0, 0});

	if (expression.empty())
		throw std::invalid_argument("Empty expression");
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
				stack.push(left / right);
		}
		else if (std::isdigit(token[0]))
			stack.push(std::stoi(token));
		else
			throw std::invalid_argument("Invalid expression");
	}
	return (stack.top());
}
/* ************************************************************************** */
