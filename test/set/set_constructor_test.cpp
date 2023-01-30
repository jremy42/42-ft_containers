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
	std::fstream f;
	f.open("random_numbers.txt", std::fstream::in);
	if (!f.is_open())
	{
		std::cout << "file not open" << std::endl;
		return 0;
	}
	std::cout << "set constructor test" << std::endl;
	NAMESPACE::set<TEST_TYPE> s;
	std::cout << s << std::endl;
	NAMESPACE::set<TEST_TYPE> s2(s);
	std::cout << s2 << std::endl;
	std::string buf;
	//getline 
	while(getline(f, buf, '\n'))
		s2.insert(atoi(buf.c_str()));
	
	std::cout << s2 << std::endl;
	
	NAMESPACE::set<TEST_TYPE> s3(s2);

	std::cout << s3 << std::endl;

	NAMESPACE::set<TEST_TYPE> s4(s3.begin(), s3.end());

	std::cout << "s4" << s4 << std::endl;

	NAMESPACE::set<TEST_TYPE>::iterator it = s3.begin();

	for (int i = 0; i < 5; i++)
		it++;

	NAMESPACE::set<TEST_TYPE> s5(s3.begin(), it);

	std::cout << "s5:" << s5 << std::endl;

	NAMESPACE::set<TEST_TYPE>::const_iterator it2 = s.begin();
	std::cout << *it2 << std::endl;
	NAMESPACE::set<TEST_TYPE>::const_iterator it3;
	it3 = it;
	NAMESPACE::set<TEST_TYPE>::iterator it4;

	NAMESPACE::set<TEST_TYPE> s6(s5.rbegin(), s5.rend());
	std::cout << s6 << std::endl;
	NAMESPACE::set<TEST_TYPE> s7;
	s7 = s6;
	std::cout << s7 << std::endl; 
	return 0;
}