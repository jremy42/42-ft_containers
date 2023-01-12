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

	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m;

	for (int i = 0; i < 15; i++)
	{
		m.insert(NAMESPACE::make_pair(i, i));
	}
	NAMESPACE::pair<NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator, NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator> ret;
	ret = m.equal_range(5);
	while (ret.first != ret.second)
	{
		std::cout << ret.first->first << " " << ret.first->second << std::endl;
		ret.first++;
	}

	return 0;
}