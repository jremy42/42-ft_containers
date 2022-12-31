#include "vector.hpp"
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
	std::cout << "vector empty test" << std::endl;
	NAMESPACE::vector<int> v;
	std::cout << v.size() << std::endl;
	std::cout << v.empty() << std::endl;
	v.push_back(1);
	std::cout << v.size() << std::endl;
	std::cout << v.empty() << std::endl;
	return 0;
}