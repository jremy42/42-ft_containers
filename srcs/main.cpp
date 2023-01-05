#include <iostream>
#include "pair.hpp"
#include "rbtree.hpp"

int main()
{
  ft::rbtree<int> tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(1);
  tree.insert(4);
  tree.insert(12);
  tree.print_tree();
  tree.insert(8);
  tree.print_tree();
}