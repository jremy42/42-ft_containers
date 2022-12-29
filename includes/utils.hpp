# include "vector.hpp"
# include <iostream>
# include <vector>
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
