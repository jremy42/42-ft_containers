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
	std::cout << "set erase test" << std::endl;
	std::fstream f;
	std::string buf;
	f.open("random_numbers.txt", std::fstream::in);
	if (!f.is_open())
	{
		std::cout << "file not open" << std::endl;
		return 0;
	}
	NAMESPACE::set<int> s;
	while (getline(f, buf, '\n'))
	{
		s.insert(atoi(buf.c_str()));
	}

	NAMESPACE::set<int>s2(s);

	//erase with key
	NAMESPACE::set<int>::iterator it = s.begin();
	for (int i = 0; i < 5; i++)
	{
		it++;
	}
	s.erase(it);
	std::cout <<__LINE__ << s << std::endl;

	NAMESPACE::set<int>::iterator it2 = s2.begin();
	for (int i = 0; i < 5; i++)
	{
		it2++;
	}
	s2.erase(it2);
	std::cout << s2 << std::endl;
	std::cout << "erase with iterator" << std::endl;
	it2 = s2.begin();
	//NAMESPACE::set<int>::iterator ite = s2.end();
	s2.erase(s2.begin(), s2.end());
	std::cout << s2 << std::endl;
	
	NAMESPACE::set<int>::iterator it4 = s.begin();
	NAMESPACE::set<int>::iterator ite4 = s.end();
	it4++;
	s.erase(it4, ite4);
	std::cout << s << std::endl;

}