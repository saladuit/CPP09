/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  Subset.hpp                                      |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 15/12/2023 04:56:30 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 15/12/2023 04:59:40 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSET_HPP
#define SUBSET_HPP

#include "Slice.hpp"
#include <cstddef>

template <typename Container>
class Subset
{
  private:
	Slice<Container> _slice;
	Subset &_parent;

  public:
	Subset() : _slice(), _parent(*this){};
	Subset(const Container &container) : _slice(container), _parent(*this){};
	Subset(const Subset &other, Slice<Container> start, Slice<Container> end)
		: _slice(other._slice, start, end), _parent(other){};
	Subset &operator=(const Container &container)
	{
		if (this != &container)
		{
			_slice = container;
		}
		return (*this);
	};
	~Subset(){};
	const Slice<Container> &getSlice() const
	{
		return (_slice);
	};
	const Subset &getParent() const
	{
		return (_parent);
	};
	size_t size() const
	{
		return (_slice.size());
	};
	bool empty() const
	{
		return (_slice.empty());
	};
	void insertionSort()
	{
		_slice.insertionSort();
	};
	void move(size_t from, size_t to)
	{
		_slice.move(from, to);
	};
	void swap(size_t from, size_t to)
	{
		_slice.swap(from, to);
	};
	size_t binarySearch(const typename Container::value_type &value) const
	{
		return (_slice.binarySearch(value));
	};
	const typename Container::value_type &findMin() const
	{
		return (_slice.findMin());
	};
	const typename Container::value_type &findMax() const
	{
		return (_slice.findMax());
	};
	bool isSorted() const
	{
		return (_slice.isSorted());
	};
};

#endif
