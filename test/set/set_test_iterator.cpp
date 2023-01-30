#include "vector.hpp"
#include <iostream>
#include <vector>
#include "set.hpp"
#include <set>

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

#ifndef TEST_TYPE
# define TEST_TYPE int
#endif


int main()
{
	std::cout << "set insert test" << std::endl;
	NAMESPACE::set<TEST_TYPE> m;
	for (int i = 0; i < 100; i++)
		m.insert(i);
	NAMESPACE::set<TEST_TYPE>::iterator it = m.begin();
	NAMESPACE::set<TEST_TYPE>::iterator ite = m.end();

	//std::cout << "it value:" << *it << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << *it << std::endl;
		it++;
	}
	
	for (int i = 0; i < 100; i++)
	{		ite--;

		std::cout << *ite << std::endl;
	}

	NAMESPACE::set<TEST_TYPE>::reverse_iterator rit = m.rbegin();
	NAMESPACE::set<TEST_TYPE>::reverse_iterator rite = m.rend();

	for (int i = 0; i < 100; i++)
	{
		std::cout << *rit << std::endl;
		rit++;
	}
	for (int i = 0; i < 100; i++)
	{		rite--;
		std::cout << *rite << std::endl;
	}



	
	return 0;
}