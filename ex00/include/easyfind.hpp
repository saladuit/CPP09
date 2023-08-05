/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:26:52 by safoh             #+#    #+#             */
/*   Updated: 2023/08/05 15:55:25 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <Color.hpp>
#include <Defines.hpp>
#include <algorithm>
#include <iostream>

template <typename T>

int easyfind(T &container, int n)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return *it;
	else
		throw std::exception();
}
/* **************************Private_member_functions************************ */

/* **************************Public_member_functions************************* */

/* *******************************Constructors******************************* */

/* ********************************Overloads********************************* */

#endif
/* ************************************************************************** */
