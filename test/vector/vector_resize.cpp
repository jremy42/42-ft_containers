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
	std::cout << "vector resize test" << std::endl;
	try
	{
	
		NAMESPACE::vector<int> v;
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
		v.resize(10, 1);
		std::cout << v << std::endl;
		v.resize(5);
		std::cout << v << std::endl;
		v.resize(15, 1);
		std::cout << v << std::endl;

		v.resize(-20);
		std::cout << v << std::endl;

		v.resize(0);
		std::cout << v << std::endl;

		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}