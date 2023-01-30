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
		if (i > 3 && i < 8)
			continue;
		m.insert(NAMESPACE::make_pair(i, i));
	}
	std::cout << m << std::endl;
	std::cout << "upper bound 5 " << m.upper_bound(5)->first << std::endl;
	std::cout << "lower bound 5 " << m.lower_bound(5)->first << std::endl;

	NAMESPACE::pair<NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator, NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator> ret;
	ret = m.equal_range(5);
	std::cout <<  "ret first " << ret.first->first << std::endl;
	std::cout <<  "ret second " << ret.second->first << std::endl;
	m.clear();

	for (int i = 0; i < 15; i++)
	{
		m.insert(NAMESPACE::make_pair(i, i));
	}
	std::cout << m << std::endl;
	std::cout << "upper bound 5 " << m.upper_bound(5)->first << std::endl;
	std::cout << "lower bound 5 " << m.lower_bound(5)->first << std::endl;
	std::cout << "upper bound 1 " << m.upper_bound(1)->first << std::endl;
	std::cout << "lower bound 14 " << m.lower_bound(14)->first << std::endl;
	std::cout << "lower bound 0 " << m.lower_bound(0)->first << std::endl;

	ret = m.equal_range(5);
	std::cout <<  "ret first " << ret.first->first << std::endl;
	std::cout <<  "ret second " << ret.second->first << std::endl;
	while (ret.first != ret.second)
	{
		std::cout << ret.first->first << " " << ret.first->second << std::endl;
		ret.first++;
	}


	return 0;
}