/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  JacobSequence.hpp                               |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 15/12/2023 10:20:59 AM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 15/12/2023 10:30:58 AM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef JACOBSEQUENCE_HPP
#define JACOBSEQUENCE_HPP
// https://github.com/Morwenn/cpp-sort/blob/1.x.y-stable/include/cpp-sort/detail/merge_insertion_sort.h
#include <cstddef>

class JacobSequence
{
  private:
	size_t _current_value;
	size_t _next_value;

  public:
	JacobSequence();
	JacobSequence(const JacobSequence &src);
	JacobSequence &operator=(const JacobSequence &rhs);
	~JacobSequence();

	size_t getCurrentValue() const;
	size_t getNextValue() const;
	size_t next();
};

#endif
