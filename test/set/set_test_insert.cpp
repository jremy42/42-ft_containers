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
	std::cout << "set insert test" << std::endl;
	std::fstream f;
	std::string buf;
	f.open("random_numbers.txt", std::fstream::in);
	if (!f.is_open())
	{
		std::cout << "file not open" << std::endl;
		return 0;
	}
	NAMESPACE::set<int> m0;
	NAMESPACE::set<int> m;
	m.insert(1);
	m.insert( 2);

	if (m.insert(1).second == false)
		std::cout << "insert failed" << std::endl;
	if (m.insert(2).second == false)
		std::cout << "insert failed" << std::endl;
	if (m.insert(3).second == true)
		std::cout << "insert success" << std::endl;
	std::cout << *(m.insert(4).first) << std::endl;
	while (getline(f, buf, '\n'))
	{
		m.insert(atoi(buf.c_str()));
		m0.insert(m0.begin(), atoi(buf.c_str()));

	}
	std::cout << m << std::endl;
	std::cout << m0 << std::endl;
	NAMESPACE::set<TEST_TYPE>::iterator it = m.begin();
	NAMESPACE::set<TEST_TYPE>::iterator ite = m.end();

	NAMESPACE::set<TEST_TYPE> m2;
	m2.insert(it, ite);
	for (NAMESPACE::set<TEST_TYPE>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	
	//same with const_iterator
	NAMESPACE::set<TEST_TYPE>::const_iterator cit = m.begin();
	NAMESPACE::set<TEST_TYPE>::const_iterator cite = m.end();
	NAMESPACE::set<TEST_TYPE> m3;
	m3.insert(cit, cite);
	for (NAMESPACE::set<TEST_TYPE>::const_iterator it = m3.begin(); it != m3.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}