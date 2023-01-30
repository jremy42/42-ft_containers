#include "vector.hpp"
#include <iostream>
#include <vector>
#include "set.hpp"
#include <set>
#include "utils.hpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#ifndef TEST_TYPE
# define TEST_TYPE int
#endif

class A
{
public:
	A() {}
	~A() {}
	A(A const &a) { (void)a; }
	A &operator=(A const &a) { (void)a; return *this; }
};

int main()
{
	std::fstream f;
	f.open("random_numbers.txt", std::fstream::in);
	if (!f.is_open())
	{
		std::cout << "file not open" << std::endl;
		return 0;
	}
	NAMESPACE::set<TEST_TYPE> s;
	std::cout << s.empty() << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << s.max_size() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		s.insert(i);
	}
	NAMESPACE::set<TEST_TYPE> s2;

	s2.swap(s);
	std::cout << s << std::endl;
	std::cout << s2 << std::endl;
	return 0;
}