/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                      :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:07:42 by safoh             #+#    #+#             */
/*   Updated: 2023/08/05 16:16:26 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() : std::stack<T>()
	{
	}
	MutantStack(const MutantStack &other) : std::stack<T>(other)
	{
	}
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	virtual ~MutantStack()
	{
	}
	iterator begin()
	{
		return std::stack<T>::c.begin();
	}
	iterator end()
	{
		return std::stack<T>::c.end();
	}
};

/* **************************Private_member_functions************************ */

/* **************************Public_member_functions************************* */

/* *******************************Constructors******************************* */

/* ********************************Overloads********************************* */

#endif
/* ************************************************************************** */
