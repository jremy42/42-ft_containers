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
#include <algorithm>
#include "node_iterator.hpp"

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

void print(const int &p)
{
	std::cout << p << std::endl;
}

int main()
{
	std::cout << "set algo test" << std::endl;
	std::fstream f;
	std::string buf;
	f.open("random_numbers.txt", std::fstream::in);
	if (!f.is_open())
	{
		std::cout << "file not open" << std::endl;
		return 0;
	}
	NAMESPACE::set<int> m;


	while (getline(f, buf, '\n'))
		m.insert(atoi(buf.c_str()));

	std::for_each(m.begin(), m.end(), print);
	return 0;
}