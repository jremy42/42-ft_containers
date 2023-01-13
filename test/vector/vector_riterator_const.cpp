#include "vector.hpp"
#include "iterator.hpp"
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
	std::cout << "test riterator constness" << std::endl;
	//test constness with reverse_iterator
	NAMESPACE::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	NAMESPACE::vector<int>::reverse_iterator rit = v.rbegin();
	NAMESPACE::vector<int>::reverse_iterator rite = v.rend();
	rit = v.rbegin();
	std::cout << "rit = v.rbegin() " << (*rit) << std::endl;
	rite = rit;
	std::cout << "rite = rit " << (*rite) << std::endl;
	NAMESPACE::vector<int>::const_reverse_iterator crit = v.rbegin();
	NAMESPACE::vector<int>::const_reverse_iterator crite = v.rend();
	crit = rit;
	std::cout << "crit = rit " << (*crit) << std::endl;
	crit = rite;
	std::cout << "crit = rite " << (*crit) << std::endl;
	--crite;
	std::cout << "++crite " << (*crite) << std::endl;

    return 0;
}