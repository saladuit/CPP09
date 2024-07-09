#ifndef SLICE_HPP
#define SLICE_HPP

#include <cstddef>
#include <exception>
#include <iterator>
#include <string>

template <typename C>
class Slice
{
  public:
	typedef typename C::value_type value_type;
	Slice() = delete;
	Slice(C &container)
		: _container(container), _size(container.size()), _has_stray(_size % 1),
		  _start(0), _end(_size){};
	Slice(C &container, size_t start, size_t end)
		: _container(container), _size(end - start), _has_stray(_size % 1),
		  _start(start), _end(end){};
	Slice &operator=(const Slice &other) = delete;
	value_type &operator[](size_t index)
	{
		if (index >= _size)
		{
			throw OutOfRange(
				"Out of range index " + std::to_string(index) +
				" is out of range (" + std::to_string(index + _start) + "); " +
				std::to_string(_size) + std::string(" elements") +
				" and has_stray ==  " + std::to_string(_has_stray));
		}
		return _container[_start + index];
	}
	Slice getSubSlice(size_t start, size_t end)
	{
		if (start > end)
		{
			throw std::out_of_range("Start index is greater than end index");
		}
		return Slice<C>(_container, _start + start, _start + end);
	}
	Slice getSubSlice(size_t start)
	{
		if (start > _size)
		{
			throw std::out_of_range("Start index is greater than end index");
		}
		return Slice<C>(_container, _start + start, _end);
	}
	~Slice() = default;

	size_t size() const
	{
		return _size;
	}

	void erase(size_t from_index)
	{
		_container.erase(std::next(_container.begin(), _start + from_index));
	}

	void insert(size_t to_index, value_type value)
	{
		_container.insert(std::next(_container.begin(), _start + to_index),
						  value);
	}
	bool has_stray() const
	{
		return _has_stray;
	}
	class OutOfRange : public std::out_of_range
	{
	  public:
		OutOfRange(const std::string &message) : std::out_of_range(message){};
	};

  private:
	C &_container;
	size_t _size;
	bool _has_stray;
	size_t _start;
	size_t _end;
};

#endif
