#include "vector.hpp"
#include "iterator.hpp"
#include <iostream>
#include <algorithm>
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
   std::cout << "test iterator algo" << std::endl;
    NAMESPACE::vector<int> v;
    // test iterator
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // test algo
    std::cout << "test algo" << std::endl;
    std::cout << *(std::find(v.begin(), v.end(), 3)) << std::endl;
    std::cout << *(std::find(v.begin(), v.end(), 1)) << std::endl;
    std::cout << *(std::find(v.begin(), v.end(), 4)) << std::endl;
    std::cout << *(std::find(v.begin(), v.end(), 2)) << std::endl;

	std::cout << "test find false" << std::endl;
	std::cout << ((std::find(v.begin(), v.end(), 5)) == v.end()) << std::endl;
	// test algo with reverse iterator
	std::cout << "test algo with reverse iterator" << std::endl;
	std::cout << *(std::find(v.rbegin(), v.rend(), 3)) << std::endl;
	std::cout << *(std::find(v.rbegin(), v.rend(), 1)) << std::endl;
	std::cout << *(std::find(v.rbegin(), v.rend(), 4)) << std::endl;
	std::cout << *(std::find(v.rbegin(), v.rend(), 2)) << std::endl;
	
    return 0;
}