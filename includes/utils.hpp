# include "vector.hpp"
# include "stack.hpp"
# include <iostream>
# include <vector>
# include <stack>
# ifndef NAMESPACE
#  define NAMESPACE ft
# endif

// surcharge operator<< pour afficher un vector
template <typename T>
std::ostream &operator<<(std::ostream &os, const NAMESPACE::vector<T> &v)
{
	os << "size: " << v.size() << " capacity: " << v.capacity() << " content: ";
	for (size_t i = 0; i < v.size(); i++)
		os << v[i] << " ";
	return os;
}
// surcharge operatr << pour afficher une stack
template <typename T>
std::ostream &operator<<(std::ostream &os, const NAMESPACE::stack<T> &s)
{
	NAMESPACE::stack<T> tmp(s);
	os << "size: " << tmp.size() << " content: ";
	for (size_t i = 0; i < tmp.size(); i++)
	{
		os << tmp.top() << " ";
		tmp.pop();
	}
	return os;
}
