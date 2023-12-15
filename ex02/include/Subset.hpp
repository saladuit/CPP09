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

template <typename Container>
class Subset
{
  private:
	Slice<Container> _slice;
	Subset &_parent;

  public:
	Subset() : _slice(), _parent(*this){};
	Subset(const Container &container) : _slice(container), _parent(*this){};
	Subset(const Subset &other)
		: _slice(other._slice), _parent(other._parent){};
	Subset &operator=(const Container &container)
	{
		if (this != &container)
		{
			_slice = container;
		}
		return (*this);
	};
	~Subset(){};
};

#endif
