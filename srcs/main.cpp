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
	for (int i = 0; i < 10; i++)
	{
		m.insert(NAMESPACE::make_pair(i, i + 3));
		std::cout << "insert" << i << std::endl;
	}
	NAMESPACE::map<int, int>::iterator ite = m.end();

	std::cout << ite->first << std::endl;

	
	return 0;
}