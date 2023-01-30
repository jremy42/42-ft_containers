#include "vector.hpp"
#include <iostream>
#include "map.hpp"
#include "utils.hpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


#ifndef TEST_TYPE
# define TEST_TYPE int
#endif

int main()
{
	ft::map<int, int> m;
	std::fstream f;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int insert = rand() % 100;
		m.insert(NAMESPACE::make_pair( insert, insert));
	}
	std::cout << m.print()	<< std::endl;
	return 0;
}