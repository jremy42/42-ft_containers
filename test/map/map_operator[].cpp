#include "vector.hpp"
#include <iostream>
#include <vector>
#include "map.hpp"
#include <map>
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
	return 0;
}