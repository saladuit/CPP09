/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:07:42 by safoh             #+#    #+#             */
/*   Updated: 2023/08/05 16:16:26 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <Color.hpp>
#include <Defines.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
  private:
	std::vector<unsigned int> _container;
	unsigned int _size;
	unsigned int _maxSize;

  public:
	Span();
	Span(unsigned int n);
	Span(Span const &src);
	~Span();
	Span &operator=(Span const &src);
	void addNumber(unsigned int const &n);
	void addNumber(unsigned int const &n, unsigned int const &amount);
	template <typename Iterator>
	void addRange(Iterator start, Iterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	unsigned int size() const;
	unsigned int maxSize() const;
	std::vector<unsigned int> getContainer() const;
	void printContainer() const;
	void printContainer(std::string const &color) const;
};

/* **************************Private_member_functions************************ */

/* **************************Public_member_functions************************* */

/* *******************************Constructors******************************* */

/* ********************************Overloads********************************* */

#include "../src/Span.tpp"
#endif
/* ************************************************************************** */
