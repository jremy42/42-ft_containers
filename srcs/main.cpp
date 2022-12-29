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
	NAMESPACE::vector<int> v;
	std::cout << v.size() << std::endl;
	v.push_back(1);
	std::cout << v.size() << std::endl;
	v.push_back(2);
	std::cout << v.size() << std::endl;
	v.push_back(3);
	std::cout << v.size() << std::endl;
	v.pop_back();
	std::cout << v.size() << std::endl;
	v.pop_back();
	std::cout << v.size() << std::endl;
	v.pop_back();
	std::cout << v.size() << std::endl;
	//v.pop_back();
	//std::cout << v.size() << std::endl;
	NAMESPACE::vector<A> v2;
	std::cout << v2.size() << std::endl;
	v2.push_back(A());
	std::cout << v2.size() << std::endl;
	v2.push_back(A());
	std::cout << v2.size() << std::endl;
	v2.pop_back();
	std::cout << v2.size() << std::endl;
	v2.pop_back();
	std::cout << v2.size() << std::endl;
	//v2.pop_back();
	//std::cout << v2.size() << std::endl;
	return 0;
}