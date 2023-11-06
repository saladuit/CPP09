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

template <typename T>
class Span
{
  private:
	std::vector<T> _container;
	unsigned int _size;
	unsigned int _maxSize;
	Span();

  public:
	Span(unsigned int n);
	Span(Span const &src);
	~Span();
	Span &operator=(Span const &src);
	void addNumber(T const &n);
	void addNumber(T const &n, unsigned int const &amount);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	unsigned int size() const;
	unsigned int maxSize() const;
	std::vector<T> getContainer() const;
	void printContainer() const;
	void printContainer(std::string const &color) const;
};

/* **************************Private_member_functions************************ */

/* **************************Public_member_functions************************* */

/* *******************************Constructors******************************* */

/* ********************************Overloads********************************* */

#endif
/* ************************************************************************** */
