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
	std::cout << "map insert test" << std::endl;
	std::fstream f;
	std::string buf;
	f.open("random_numbers.txt", std::fstream::in);
	if (!f.is_open())
	{
		std::cout << "file not open" << std::endl;
		return 0;
	}
	NAMESPACE::map<int, int> m;
	m.insert(NAMESPACE::make_pair(1, 1));
	m.insert(NAMESPACE::make_pair(2, 2));

	if (m.insert(NAMESPACE::make_pair(1, 1)).second == false)
		std::cout << "insert failed" << std::endl;
	if (m.insert(NAMESPACE::make_pair(2, 2)).second == false)
		std::cout << "insert failed" << std::endl;
	if (m.insert(NAMESPACE::make_pair(3, 3)).second == true)
		std::cout << "insert success" << std::endl;
	std::cout << m.insert(NAMESPACE::make_pair(4, 4)).first->first << std::endl;
	while (getline(f, buf, '\n'))
	{
		m.insert(NAMESPACE::make_pair(atoi(buf.c_str()), atoi(buf.c_str())));
	}
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator it = m.begin();
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator ite = m.end();

	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m2;
	m2.insert(it, ite);
	for (NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		std::cout << it->first << std::endl;
	}
	
	//same with const_iterator
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_iterator cit = m.begin();
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_iterator cite = m.end();
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m3;
	m3.insert(cit, cite);
	for (NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_iterator it = m3.begin(); it != m3.end(); it++)
	{
		std::cout << it->first << std::endl;
	}

	return 0;
}