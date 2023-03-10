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
	std::vector<TEST_TYPE> v;
	std::string buf;
	//getline 
	while(getline(f, buf, '\n'))
	{
		m.insert(NAMESPACE::make_pair(atoi(buf.c_str()), atoi(buf.c_str())));
		v.push_back(atoi(buf.c_str()));

	}
	for (std::vector<TEST_TYPE>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << m[*it] << std::endl;
	}

		for (std::vector<TEST_TYPE>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << m.at(*it) << std::endl;
	}

	return 0;
}