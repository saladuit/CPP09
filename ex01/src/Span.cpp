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

template <typename T>
void Span<T>::addNumber(T const &n)
{
	if (this->_size >= this->_maxSize)
		throw std::length_error("Span is full");
	this->_container.push_back(n);
	this->_size++;
}

template <typename T>
void Span<T>::addNumber(T const &n, unsigned int const &amount)
{
	if (this->_size + amount > this->_maxSize)
		throw std::length_error("Span is full");
	for (unsigned int i = 0; i < amount; i++)
	{
		this->_container.push_back(n);
		this->_size++;
	}
}

template <typename T>
unsigned int Span<T>::shortestSpan() const
{
	if (this->_size <= 1)
		throw std::length_error("Span is empty or has only one element");
	std::vector<T> tmp = this->_container;
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < this->_size - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < shortest)
			shortest = tmp[i + 1] - tmp[i];
	}
	return shortest;
}

template <typename T>
unsigned int Span<T>::longestSpan() const
{
	if (this->_size <= 1)
		throw std::length_error("Span is empty or has only one element");
	std::vector<T> tmp = this->_container;
	std::sort(tmp.begin(), tmp.end());
	return tmp[this->_size - 1] - tmp[0];
}

template <typename T>
unsigned int Span<T>::size() const
{
	return this->_size;
}

template <typename T>
unsigned int Span<T>::maxSize() const
{
	return this->_maxSize;
}

template <typename T>
std::vector<T> Span<T>::getContainer() const
{
	return this->_container;
}

template <typename T>
void Span<T>::printContainer() const
{
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << this->_container[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void Span<T>::printContainer(std::string const &color) const
{
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << color << this->_container[i] << RESET << " ";
	std::cout << std::endl;
}

/* *******************************Constructors******************************* */

template <typename T>
Span<T>::Span(unsigned int n) : _size(0), _maxSize(n)
{
	this->_container.reserve(n);
}

template <typename T>
Span<T>::Span(Span const &src)
{
	*this = src;
}

template <typename T>
Span<T>::~Span()
{
}

/* ********************************Overloads********************************* */

template <typename T>
Span<T> &Span<T>::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_container = src.getContainer();
		this->_size = src.size();
		this->_maxSize = src.maxSize();
	}
	return *this;
}

/* ************************************************************************** */
