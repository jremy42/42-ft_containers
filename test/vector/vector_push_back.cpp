#include "vector.hpp"
#include <iostream>
#include <vector>
#include "utils.hpp"

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
	std::cout << "vector push_back test" << std::endl;
	NAMESPACE::vector<int> v;
	std::cout << v << std::endl;
	v.push_back(1);
	std::cout << v << std::endl;
	v.push_back(2);
	std::cout << v << std::endl;
	v.push_back(3);
	std::cout << v << std::endl;
	v.pop_back();
	std::cout << v << std::endl;
	v.pop_back();
	std::cout << v << std::endl;
	v.pop_back();
	std::cout << v << std::endl;
	return 0;
}