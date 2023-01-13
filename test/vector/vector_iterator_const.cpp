#include "vector.hpp"
#include "iterator.hpp"
#include <iostream>
#include <vector>
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
	std::cout << "test iterator constness" << std::endl;
	//test constness with reverse_iterator
	NAMESPACE::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	//change with iterator
	NAMESPACE::vector<int>::iterator it = v.begin();
	NAMESPACE::vector<int>::iterator ite = v.end();
	it = v.begin();
	std::cout << "it = v.begin() " << (*it) << std::endl;
	ite = it;
	std::cout << "ite = it " << (*ite) << std::endl;
	NAMESPACE::vector<int>::const_iterator cit = v.begin();
	NAMESPACE::vector<int>::const_iterator cite = v.end();
	const NAMESPACE::vector<int>::iterator it2 = v.begin();
	cit = it;
	std::cout << "cit = it " << (*cit) << std::endl;
	cit = it2;
	std::cout << "cit = it2 " << (*cit) << std::endl;
	cite--;
	std::cout << "cite:" << *cite << std::endl;

    return 0;

    return 0;
}