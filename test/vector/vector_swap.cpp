#include "vector.hpp"
#include <iostream>
#include <vector>
#include "utils.hpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NAMESPACE
# define NAMESPACE ft
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
	std::cout << "vector swap test" << std::endl;
	NAMESPACE::vector<int> v;
	std::fstream f;
	std::string buf;
	f.open("random_numbers.txt", std::fstream::in);
	if (!f.is_open())
	{
		std::cout << "file not open" << std::endl;
		return 0;
	}
	while(getline(f, buf, '\n'))
		v.push_back(atoi(buf.c_str()));


	NAMESPACE::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);

	NAMESPACE::vector<int>::iterator it = v2.begin();
	NAMESPACE::vector<int>::iterator ite = v2.end();
	NAMESPACE::vector<int>::iterator it2 = v.begin();
	NAMESPACE::vector<int>::iterator ite2 = v.end();

	int &ref = *it;
	int &ref2 = *it2;
	std::cout << "ref: " << ref << std::endl;
	std::cout << "ref2: " << ref2 << std::endl;
	v.swap(v2);
	std::cout << "ref: " << ref << std::endl;
	std::cout << "ref2: " << ref2 << std::endl;
	std::cout << "v: " << v << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v iterator: " << *it << std::endl;
	std::cout << "v2 iterator: " << *it2 << std::endl;
	ite--;
	ite2--;
	std::cout << "v iterator: " << *ite << std::endl;
	std::cout << "v2 iterator: " << *ite2 << std::endl;

	

	return 0;
}