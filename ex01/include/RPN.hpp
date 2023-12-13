/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  RPN.hpp                                         |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 13/12/2023 02:53:33 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 13/12/2023 04:05:57 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <sstream>
#include <stack>
#include <stdexcept>

namespace RPN
{
int calculateRPN(const std::string &expression);
};

#endif

/* ************************************************************************** */
