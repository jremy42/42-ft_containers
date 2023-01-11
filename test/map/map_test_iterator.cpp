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

#ifndef TEST_TYPE
# define TEST_TYPE int
#endif


int main()
{
	std::cout << "map insert test" << std::endl;
	NAMESPACE::map<TEST_TYPE,TEST_TYPE> m;
	for (int i = 0; i < 100; i++)
		m.insert(NAMESPACE::make_pair(i, i + 3));
	NAMESPACE::map<TEST_TYPE,TEST_TYPE>::iterator it = m.begin();
	NAMESPACE::map<TEST_TYPE,TEST_TYPE>::iterator ite = m.end();

	//std::cout << "it value:" << *it << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << it->first << std::endl;
		it++;
	}
	
	for (int i = 0; i < 100; i++)
	{
		std::cout << ite->first << std::endl;
		ite--;
	}

	NAMESPACE::map<TEST_TYPE,TEST_TYPE>::reverse_iterator rit = m.rbegin();
	NAMESPACE::map<TEST_TYPE,TEST_TYPE>::reverse_iterator rite = m.rend();

	for (int i = 0; i < 100; i++)
	{
		std::cout << rit->first << std::endl;
		rit++;
	}
	for (int i = 0; i < 100; i++)
	{
		std::cout << rite->first << std::endl;
		rite--;
	}

	//same with const iterator


	
	return 0;
}