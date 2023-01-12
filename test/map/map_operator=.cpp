#include "vector.hpp"
#include <iostream>
#include <vector>
#include "map.hpp"
#include <map>
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
	std::list<NAMESPACE::pair<TEST_TYPE, TEST_TYPE> > lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(NAMESPACE::make_pair(lst_size - i, i));

	NAMESPACE::map<TEST_TYPE, TEST_TYPE> mp(lst.begin(), lst.end());
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator it = mp.begin();
	NAMESPACE::map<TEST_TYPE,TEST_TYPE>::iterator ite = mp.end();

	NAMESPACE::map<TEST_TYPE, TEST_TYPE> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
    std::cout << "mp:" << std::endl;
    std::cout << mp << std::endl;
    std::cout << "mp_range:" << std::endl;
    std::cout << mp_range << std::endl;
    std::cout << "mp_copy:" << std::endl;
    std::cout << mp_copy << std::endl;
	

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	std::cout << "mp:" << std::endl;
    std::cout << mp << std::endl;
    std::cout << "mp_range:" << std::endl;
    std::cout << mp_range << std::endl;
    std::cout << "mp_copy:" << std::endl;
    std::cout << mp_copy << std::endl;

    NAMESPACE::map<TEST_TYPE, A> m_a;

    A a1;
    A a2;

    m_a[1] = a1;
    m_a[2] = a2;

	return (0);
}