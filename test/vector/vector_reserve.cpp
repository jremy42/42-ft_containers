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
	std::cout << "vector reserve test" << std::endl;
	try
	{
	
		NAMESPACE::vector<int> v;
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
		v.reserve(10);
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
		v.reserve(5);
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
		v.reserve(15);
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
		v.reserve(-20);
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
		v.reserve(0);
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
		v.reserve(v.max_size() + 1);
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}