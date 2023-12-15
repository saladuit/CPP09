#include "JacobSequence.hpp"

JacobSequence::JacobSequence() : _current_value(0), _next_value(1)
{
}

JacobSequence::JacobSequence(const JacobSequence &src)
{
	*this = src;
}

JacobSequence &JacobSequence::operator=(const JacobSequence &rhs)
{
	if (this != &rhs)
	{
		_current_value = rhs._current_value;
		_next_value = rhs._next_value;
	}
	return *this;
}

JacobSequence::~JacobSequence()
{
}

size_t JacobSequence::getCurrentValue() const
{
	return (_current_value);
}

size_t JacobSequence::getNextValue() const
{
	return (_next_value);
}

size_t JacobSequence::next()
{
	_next_value *= 2;
	_current_value = _next_value - _current_value;
	return (_current_value);
}
