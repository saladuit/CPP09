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
						  size_t end)
	{
		size_t s = start;
		size_t ee = end;
		try
		{
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
			std::cerr << "\nend: " << ee << "\n\n";
			std::cerr << "\nsearch: " << e.what() << "\n\n";
			exit(1);
		}
	}
	void _insert_jacobsthal()
	{
#ifdef DEBUG
		for (size_t i = 0; i < _args.size(); ++i)
		{
			std::cout << _args[i] << " ";
		}
		std::cout << std::endl;
#endif
		JacobSequence jacob;
		size_t to_sort = _pair_gap;
		typename C::value_type tmp = _args[0];
		_move(0, _pair_gap - 1);
		to_sort--;
#ifdef DEBUG
		for (size_t i = 0; i < _args.size(); ++i)
		{
			std::cout << _args[i] << " ";
		}
		std::cout << '[' << tmp << ']' << std::endl;
#endif
		while (to_sort > 0)
		{
			bool sorting_stray = _args.has_stray() && to_sort == 1;

			size_t group_size = jacob.next();
			if (group_size >= to_sort)
			{
				group_size = to_sort;
				if (_args.has_stray() && !sorting_stray)
				{
					group_size--;
				}
			}
			size_t after = to_sort - group_size;
			if (_args.has_stray() && !sorting_stray)
			{
				after--;
			}
			for (size_t i = 0; i < group_size; i++)
			{
				size_t index = group_size - i - 1;
				tmp = _args[index];
				size_t index_to_move_to =
					_binary_search(_args[index], to_sort, _args.size() - after);
				_move(index, index_to_move_to - 1);

				// 75 78 53 40 76 19 70 55 39 85 91 57 20 63 68 49 52 12 36 81
				// 22 67 29 50 90 82 28 32 62
#ifdef DEBUG
				for (size_t i = 0; i < _args.size(); ++i)
				{
					std::cout << _args[i] << " ";
				}
				std::cout << '[' << tmp << ']';
				/* if (tmp == 67) */
				{
					std::cout << " gs: " << group_size
							  << " to_sort: " << to_sort
							  << " end: " << _args.size() - after
							  << " after: " << after
							  << " move_to: " << index_to_move_to;
				}
				std::cout << std::endl;
#endif
				if (index_to_move_to == _args.size() - after)
				{
					after++;
				}
				after++;
				to_sort--;
			}
		}
	}
	// 1 2 3 4 5|6 7 8 9 10
};

#endif

/* ************************************************************************** */
