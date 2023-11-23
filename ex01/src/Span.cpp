/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:18:43 by safoh             #+#    #+#             */
/*   Updated: 2023/08/05 16:20:50 by safoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

/* **************************Public_member_functions************************* */

void Span::addNumber(unsigned int const &n)
{
	if (this->_size >= this->_maxSize)
		throw std::length_error("Span is full");
	this->_container.push_back(n);
	this->_size++;
}

unsigned int Span::shortestSpan() const
{
	if (this->_size <= 1)
		throw std::length_error("Span is empty or has only one element");
	std::vector<unsigned int> tmp = this->_container;
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < this->_size - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < shortest)
			shortest = tmp[i + 1] - tmp[i];
	}
	return (shortest);
}

unsigned int Span::longestSpan() const
{
	if (this->_size <= 1)
		throw std::length_error("Span is empty or has only one element");
	std::vector<unsigned int> tmp = this->_container;
	std::sort(tmp.begin(), tmp.end());
	unsigned int longest = tmp[this->_size - 1] - tmp[0];
	for (unsigned int i = 1; i < this->_size - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] > longest)
			longest = tmp[i + 1] - tmp[i];
	}
	return (longest);
}

unsigned int Span::size() const
{
	return (this->_size);
}

unsigned int Span::maxSize() const
{
	return (this->_maxSize);
}

std::vector<unsigned int> Span::getContainer() const
{
	return (this->_container);
}

void Span::printContainer() const
{
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << this->_container[i] << " ";
	std::cout << std::endl;
}

void Span::printContainer(std::string const &color) const
{
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << color << this->_container[i] << " ";
	std::cout << std::endl;
}

/* *******************************Constructors******************************* */

Span::Span() : _size(0), _maxSize(0)
{
}

Span::Span(unsigned int n) : _size(0), _maxSize(n)
{
	this->_container.reserve(n);
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span()
{
}

/* ********************************Overloads********************************* */

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_container = src.getContainer();
		this->_size = src.size();
		this->_maxSize = src.maxSize();
	}
	return (*this);
}

/* ************************************************************************** */
