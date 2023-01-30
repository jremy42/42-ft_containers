#include "vector.hpp"
#include <iostream>
#include <vector>
#include "set.hpp"
#include <set>
#include "utils.hpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

 #ifndef NAMESPACE
# define NAMESPACE ft
#endif
    
#ifndef TEST_TYPE
# define TEST_TYPE int
#endif

class A
{
public:
	A() {}
	~A() {}
	A(A const &a) { (void)a; }
	A &operator=(A const &a) { (void)a; return *this; }
    friend std::ostream &operator<<(std::ostream &out, A const &a)
    {
        (void)a;
        out << "A";
        return out;
    }
    friend bool operator==(A const &a, A const &b)
    {
        (void)a;
        (void)b;
        return true;
    }
    friend bool operator!=(A const &a, A const &b)
    {
        (void)a;
        (void)b;
        return false;
    }
    friend bool operator<(A const &a, A const &b)
    {
        (void)a;
        (void)b;
        return false;
    }
};

int		main(void)
{
	std::list<TEST_TYPE> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(lst_size - i);

	NAMESPACE::set<TEST_TYPE> s(lst.begin(), lst.end());
	NAMESPACE::set<TEST_TYPE>::iterator it = s.begin();
	NAMESPACE::set<TEST_TYPE,TEST_TYPE>::iterator ite = s.end();

	NAMESPACE::set<TEST_TYPE> s_range(it, --(--ite));


	it = s.begin(); ite = --(--s.end());
	NAMESPACE::set<TEST_TYPE> s_copy(s);

	std::cout << "\t-- PART ONE --" << std::endl;
    std::cout << "s:" << std::endl;
    std::cout << s << std::endl;
    std::cout << "s_range:" << std::endl;
    std::cout << s_range << std::endl;
    std::cout << "s_copy:" << std::endl;
    std::cout << s_copy << std::endl;
	

	s = s_copy;
	s_copy = s_range;
	s_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	std::cout << "s:" << std::endl;
    std::cout << s << std::endl;
    std::cout << "s_range:" << std::endl;
    std::cout << s_range << std::endl;
    std::cout << "s_copy:" << std::endl;
    std::cout << s_copy << std::endl;

	return (0);
}