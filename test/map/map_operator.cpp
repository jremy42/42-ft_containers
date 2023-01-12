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
	std::cout << "map operators test" << std::endl;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m;
	for (int i = 0; i < 100; i++)
	{
		m.insert(NAMESPACE::make_pair(i, i));
	}
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m2;
	for (int i = 0; i < 100; i++)
	{
		m2.insert(NAMESPACE::make_pair(i - 1, i - 1));
	}
	std::cout << "m == m2: " << (m == m2) << std::endl;
	std::cout << "m != m2: " << (m != m2) << std::endl;	
	std::cout << "m < m2: " << (m < m2) << std::endl;
	std::cout << "m <= m2: " << (m <= m2) << std::endl;
	std::cout << "m > m2: " << (m > m2) << std::endl;
	m.insert(NAMESPACE::make_pair(100, 100));

	std::cout << "m == m2: " << (m == m2) << std::endl;
	std::cout << "m != m2: " << (m != m2) << std::endl;	
	std::cout << "m < m2: " << (m < m2) << std::endl;
	std::cout << "m <= m2: " << (m <= m2) << std::endl;
	std::cout << "m > m2: " << (m > m2) << std::endl;
	return 0;
}