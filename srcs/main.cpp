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
	map.insert(ft::make_pair(1, 1));
	map.insert(ft::make_pair(2, 2));
	map.insert(ft::make_pair(3, 3));
	map.insert(ft::make_pair(4, 4));
	map.print();
}
