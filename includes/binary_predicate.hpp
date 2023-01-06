#ifndef BINARY_PREDICATE_HPP
#define BINARY_PREDICATE_HPP

#include <memory>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace ft{

	template <class T1, class T2, typename Result>
	struct binary_function
	{
		typedef T1 first_argument_type;
		typedef T2 second_argument_type;
		typedef Result result_type;
	};
	template <class T>
	struct less : public ft::binary_function<T, T, bool>
	{
		bool operator() (const T& x, const T& y) const { return x < y; }
	};
};
#endif