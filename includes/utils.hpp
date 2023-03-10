# include "vector.hpp"
# include "stack.hpp"
# include <iostream>
# include <vector>
# include <stack>
# include "map.hpp"
# include <map>
# include "pair.hpp"
# include "set.hpp"
# include <set>

# ifndef NAMESPACE
#  define NAMESPACE ft
# endif

template <typename T>
std::ostream &operator<<(std::ostream &os, const NAMESPACE::vector<T> &v)
{
	os << "size: " << v.size() << " capacity: " << v.capacity() << " content: ";
	for (size_t i = 0; i < v.size(); i++)
		os << v[i] << " ";
	return os;
}
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

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
	os << "[" << p.first << "|" << p.second << "]" << std::endl;
	return os;
}


template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const NAMESPACE::map<T1, T2> &m)
{
	os << "size: " << m.size() << " content: ";
	for (typename NAMESPACE::map<T1, T2>::const_iterator it = m.begin(); it != m.end(); it++)
		os << it->first << ":" << it->second << " ";
	return os;
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const NAMESPACE::set<T> &s)
{
	os << "size: " << s.size() << " content: ";
	for (typename NAMESPACE::set<T>::const_iterator it = s.begin(); it != s.end(); it++)
		os << *it << " ";
	return os;
}
