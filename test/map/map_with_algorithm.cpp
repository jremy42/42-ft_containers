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

void print(const NAMESPACE::pair<int, int> &p)
{
	std::cout << p << std::endl;
}

int main()
{
	std::cout << "map algo test" << std::endl;
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
		m.insert(NAMESPACE::make_pair(atoi(buf.c_str()), atoi(buf.c_str())));

	std::for_each(m.begin(), m.end(), print);
	return 0;
}