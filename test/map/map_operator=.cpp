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
	return (0);
}