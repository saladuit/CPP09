#include "JacobSequence.hpp"

JacobSequence::JacobSequence() : _next_value(0), _power_of_2(1)
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
		_next_value = rhs._next_value;
		_power_of_2 = rhs._power_of_2;
	}
	return *this;
}

JacobSequence::~JacobSequence()
{
}

size_t JacobSequence::next()
{
	_power_of_2 *= 2;
	_next_value = _power_of_2 - _next_value;
	return (_next_value);
}
