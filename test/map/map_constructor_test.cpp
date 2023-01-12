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
	std::cout << "map constructor test" << std::endl;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m;
	std::cout << m << std::endl;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m2(m);
	std::cout << m2 << std::endl;
	std::string buf;
	//getline 
	while(getline(f, buf, '\n'))
		m2.insert(NAMESPACE::make_pair(atoi(buf.c_str()), atoi(buf.c_str())));
	
	std::cout << m2 << std::endl;
	
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m3(m2);

	std::cout << m3 << std::endl;

	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m4(m3.begin(), m3.end());

	std::cout << "m4" << m4 << std::endl;

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator it = m3.begin();

	for (int i = 0; i < 5; i++)
		it++;

	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m5(m3.begin(), it);

	std::cout << "m5:" << m5 << std::endl;

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_iterator it2 = m.begin();
	std::cout << *it2 << std::endl;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_iterator it3;
	it3 = it;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator it4;

	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m6(m5.rbegin(), m5.rend());
	std::cout << m6 << std::endl;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> m7;
	m7 = m6;
	std::cout << m7 << std::endl; 
	return 0;
}