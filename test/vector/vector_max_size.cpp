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
	std::cout << "vector max size test" << std::endl;
	std::cout << "Unsigned Char max size:" << NAMESPACE::vector<unsigned char>().max_size() << std::endl;
	std::cout << "Unsigned Short max size:" << NAMESPACE::vector<unsigned short>().max_size() << std::endl;
	std::cout << "Unsigned Int max size:" << NAMESPACE::vector<unsigned int>().max_size() << std::endl;
	std::cout << "Unsigned Long max size:" << NAMESPACE::vector<unsigned long>().max_size() << std::endl;
	std::cout << "Unsigned Long Long max size:" << NAMESPACE::vector<unsigned long long>().max_size() << std::endl;
	std::cout << "Char max size:" << NAMESPACE::vector<char>().max_size() << std::endl;
	std::cout << "Short max size:" << NAMESPACE::vector<short>().max_size() << std::endl;
	std::cout << "Int max size:" << NAMESPACE::vector<int>().max_size() << std::endl;
	std::cout << "Long max size:" << NAMESPACE::vector<long>().max_size() << std::endl;
	std::cout << "Long Long max size:" << NAMESPACE::vector<long long>().max_size() 		<< std::endl;
	std::cout << "Float max size:" << NAMESPACE::vector<float>().max_size() << std::endl;
	std::cout << "Double max size:" << NAMESPACE::vector<double>().max_size() << std::endl;
	std::cout << "Long Double max size:" << NAMESPACE::vector<long double>().max_size() << std::endl;
	std::cout << "String max size:" << NAMESPACE::vector<std::string>().max_size() << std::endl;
	//std::cout << "Vector max size:" << NAMESPACE::vector<NAMESPACE::vector<int> >().max_size() << std::endl;
	std::cout << "A max size:" << NAMESPACE::vector<A>().max_size() << std::endl;
	return 0;
}