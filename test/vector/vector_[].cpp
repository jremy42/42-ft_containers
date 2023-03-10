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
	std::cout << "vector [] test" << std::endl;
	NAMESPACE::vector<int> v;
	v.push_back(1);
	std::cout << v[0] << std::endl;
	v.push_back(2);
	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;
	v.push_back(3);
	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;
	std::cout << v[2] << std::endl;
	v.pop_back();
	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;
	v.pop_back();
	std::cout << v[0] << std::endl;
	return 0;
}