/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  Slice.hpp                                       |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 15/12/2023 03:36:48 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 15/12/2023 03:36:48 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_HPP
#define SLICE_HPP

template <typename Container>
class Slice
{
  private:
	typename Container::iterator _start;
	typename Container::iterator _end;

  public:
	Slice() : _start(), _end(){};
	Slice(Container &c) : _start(c.begin()), _end(c.end()){};
	Slice(const Slice &other) : _start(other._start), _end(other._end){};
	Slice &operator=(const Slice &rhs);
	~Slice();
};

#endif
