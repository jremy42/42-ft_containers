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
	std::cout << "set operators test" << std::endl;
	NAMESPACE::set<TEST_TYPE> s;
	for (int i = 0; i < 100; i++)
	{
		s.insert(i);
	}
	NAMESPACE::set<TEST_TYPE> s2;
	for (int i = 0; i < 100; i++)
	{
		s2.insert(i - 1);
	}
	std::cout << "s == s2: " << (s == s2) << std::endl;
	std::cout << "s != s2: " << (s != s2) << std::endl;	
	std::cout << "s < s2: " << (s < s2) << std::endl;
	std::cout << "s <= s2: " << (s <= s2) << std::endl;
	std::cout << "s > s2: " << (s > s2) << std::endl;
	s.insert(100);

	std::cout << "s == s2: " << (s == s2) << std::endl;
	std::cout << "s != s2: " << (s != s2) << std::endl;	
	std::cout << "s < s2: " << (s < s2) << std::endl;
	std::cout << "s <= s2: " << (s <= s2) << std::endl;
	std::cout << "s > s2: " << (s > s2) << std::endl;
	return 0;
}