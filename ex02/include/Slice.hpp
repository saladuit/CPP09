#ifndef SLICE_HPP
#define SLICE_HPP

#include <cstddef>
#include <iterator>

template <typename C>
class Slice
{
  public:
	typedef typename C::value_type value_type;
	Slice() = delete;
	Slice(C &container)
		: _container(container), _size(container.size()), _start(0),
		  _end(_size){};
	Slice(C &container, size_t start, size_t end)
		: _container(container), _size(end - start), _start(start), _end(end){};
	/* Slice(Slice &other) */
	/* 	: _container(other._container), _size(other._size), */
	/* 	  _start(other._start), _end(other._end){}; */
	Slice &operator=(const Slice &other) = delete;
	value_type &operator[](size_t index)
	{
		return _container[_start + index];
	}
	Slice getSubSlice(size_t start, size_t end)
	{
		return Slice<C>(_container, _start + start, _start + end);
	}
	Slice getSubSlice(size_t start)
	{
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

  private:
	C &_container;
	size_t _size;
	size_t _start;
	size_t _end;
};

/* a = [1, 2, 3, 4, 5, 6, 7, 8, 9] */
/* b = a[2..] => [3, 4, 5, 6, 7, 8, 9] */
/* c = b[2..] => [5, 6, 7, 8, 9] */

#endif
