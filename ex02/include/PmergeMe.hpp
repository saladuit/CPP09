#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "JacobSequence.hpp"
#include "Slice.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <stdexcept>
#include <vector>

template <typename C>
class PMergeMe
{
  public:
	PMergeMe() = delete;
	PMergeMe(C &args)
		: _args(args), _pairs(args.size() / 2),
		  _pair_gap((args.size() + 1) / 2){};
	PMergeMe(Slice<C> &args)
		: _args(args), _pairs(args.size() / 2),
		  _pair_gap((args.size() + 1) / 2){};
	PMergeMe(const PMergeMe &other) = delete;
	PMergeMe &operator=(const PMergeMe &other) = delete;
	~PMergeMe() = default;

	void sort()
	{
		_sort_pairs();
		_recursive_sort();
		try
		{
			_insert_jacobsthal();
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "\nError: " << e.what() << "\n\n";
		}
	};

  private:
	Slice<C> _args;
	size_t _pairs;
	size_t _pair_gap;
	PMergeMe *_parent = nullptr;

	void _swapped(size_t x, size_t y)
	{
		_swap(x, y);
		if (_parent)
		{
			_parent->_swapped(_pair_gap + x, _pair_gap + y);
		}
	}

	void _swap(size_t x, size_t y)
	{
		size_t tmp = _args[x];
		_args[x] = _args[y];
		_args[y] = tmp;
		if (_parent)
		{
			_parent->_swapped(x, y);
		}
	}
	void _moved(size_t from_index, size_t to_index)
	{
		_move(from_index, to_index);
		if (_parent)
		{
			_parent->_moved(_pair_gap + from_index, _pair_gap + to_index);
		}
	}
	void _move(size_t from_index, size_t to_index)
	{
		if (from_index == to_index)
		{
			return;
		}
		typename C::value_type tmp = _args[from_index];
		if (from_index < to_index)
		{
			_args.erase(from_index);
			_args.insert(to_index, tmp);
		}
		else
		{
			_args.erase(from_index);
			_args.insert(to_index + 1, tmp);
		}
		if (_parent)
		{
			_parent->_moved(from_index, to_index);
		}
	}
	void _sort_pairs()
	{
		for (size_t i = 0; i < _pairs; i++)
		{
			if (_args[i] > _args[i + _pair_gap])
			{
				_swap(i, i + _pair_gap);
			}
		}
	}
	void _recursive_sort()
	{
		Slice<C> slice = _args.getSubSlice(_pair_gap);
		PMergeMe child(slice);
		if (child._pairs < 1)
		{
			return;
		}
		child._parent = this;
		child.sort();
	}

	size_t _binary_search(typename C::value_type value, size_t start,
						  size_t len)
	{
		size_t s = start;
		try
		{
			size_t end = start + len;
			while (start != end)
			{
				size_t middle = (start + end) / 2;
				if (_args[middle] < value)
				{
					start = middle + 1;
				}
				else if (_args[middle] > value)
				{
					end = middle;
				}
				else
				{
					return middle;
				}
			}
			return end;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "\nstart: " << s << "\n\n";
			std::cerr << "\nlen: " << len << "\n\n";
			std::cerr << "\nsearch: " << e.what() << "\n\n";
			exit(1);
		}
	}
	// TODO: optimze end_index
	/* size_t end = to_sort + len; */
	void _insert_jacobsthal()
	{
		JacobSequence jacob;
		size_t to_sort = _pair_gap;
		size_t inserted = 0;
		_move(0, _pair_gap - 1);
		to_sort--;
		(void)inserted++;
		while (to_sort > 0)
		{
			size_t group_size = jacob.next();
			if (group_size >= to_sort)
			{
				group_size = to_sort;
				/* if (_args.has_stray()) // TODO: handle stray */
				/* { */
				/* 	group_size--; */
				/* } */
			}
			for (size_t i = 0; i < group_size; i++)
			{
				size_t index = group_size - i - 1;
				size_t len = inserted * 2 + 1;
				if (to_sort + len > _args.size())
				{
					len = _args.size() - to_sort;
				}
				size_t index_to_move_to =
					_binary_search(_args[index], to_sort, len);
				_move(index, index_to_move_to - 1);
				to_sort--;
				inserted++;
			}
		}
	}
	// 1 2 3 4 5|6 7 8 9 10
};

#endif

/* ************************************************************************** */
