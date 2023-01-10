#include <iostream>
#include "pair.hpp"
#include "rbtree.hpp"
#include "time.h"
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "map.hpp"
int main()
{
	ft::map<int, int> map;
	map.insert(ft::make_pair(2, 1));
	map.insert(ft::make_pair(1, 2));
	map.insert(ft::make_pair(9, 3));
	map.insert(ft::make_pair(8, 4));
	map.insert(ft::make_pair(6, 4));
	map.print();
	map.erase(8);
	map.print();
}
