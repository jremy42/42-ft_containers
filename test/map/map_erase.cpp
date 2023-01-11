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
	std::cout << "map erase test" << std::endl;
	std::fstream f;
	std::string buf;
	f.open("random_numbers.txt", std::fstream::in);
	if (!f.is_open())
	{
		std::cout << "file not open" << std::endl;
		return 0;
	}
	NAMESPACE::map<int, int> m;
	while (getline(f, buf, '\n'))
	{
		m.insert(NAMESPACE::make_pair(atoi(buf.c_str()), atoi(buf.c_str())));
	}

	NAMESPACE::map<int, int>m2(m);

	//erase with key
	NAMESPACE::map<int, int>::iterator it = m.begin();
	for (int i = 0; i < 5; i++)
	{
		it++;
	}
	m.erase(it->first);
	std::cout << m << std::endl;
	it++;
	m.erase(it->first);

	std::cout << m << std::endl;

	NAMESPACE::map<int, int>::iterator it2 = m2.begin();
	for (int i = 0; i < 5; i++)
	{
		it2++;
	}
	m2.erase(it2);
	std::cout << m2 << std::endl;
	it2 = m2.begin();
	NAMESPACE::map<int, int>::iterator ite = m2.end();

	m2.erase(it2, ite);
	std::cout << m2 << std::endl;


	//erase with iterator

	

	return 0;
}