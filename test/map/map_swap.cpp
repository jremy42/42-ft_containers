#include "vector.hpp"
#include <iostream>
#include <vector>
#include "map.hpp"
#include <map>
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
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m;
	std::cout << m.empty() << std::endl;
	std::cout << m.size() << std::endl;
	std::cout << m.max_size() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		m.insert(NAMESPACE::make_pair(i, i));
	}
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m2;

	m2.swap(m);
	std::cout << m << std::endl;
	std::cout << m2 << std::endl;
	return 0;
}