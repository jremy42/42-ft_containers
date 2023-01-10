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
	std::cout << "map insert test" << std::endl;
	NAMESPACE::map<int, int> m;
	m.insert(NAMESPACE::make_pair(1, 1));
	m.insert(NAMESPACE::make_pair(2, 2));

	if (m.insert(NAMESPACE::make_pair(1, 1)).second == false)
		std::cout << "insert failed" << std::endl;
	if (m.insert(NAMESPACE::make_pair(2, 2)).second == false)
		std::cout << "insert failed" << std::endl;
	if (m.insert(NAMESPACE::make_pair(3, 3)).second == true)
		std::cout << "insert success" << std::endl;
	std::cout << m.insert(NAMESPACE::make_pair(4, 4)).first->first << std::endl;

	
	return 0;
}