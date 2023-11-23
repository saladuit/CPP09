#pragma once
#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator start, Iterator end)
{
	for (Iterator it = start; it != end; it++)
		addNumber(*it);
}
