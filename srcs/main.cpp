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

  ft::rbtree<int> tree2;
  tree2.insert(10);
  tree2.insert(5);
  tree2.insert(15);
  tree2.insert(3);
  tree2.insert(7);
  tree2.insert(12);
  tree2.insert(17);
  tree2.insert(1);
  tree2.insert(4);
  tree2.insert(8);
  tree2.insert(1);
  tree2.print_tree();

  tree2.erase(1);

  tree2.print_tree();
  
  ft::rbtree<int> tree3;
  // insert 55 40 65 60 75 57
  tree3.insert(55);
  tree3.insert(40);
  tree3.insert(65);
  tree3.insert(60);
  tree3.insert(75);
  tree3.insert(57);
  tree3.print_tree();
  tree3.erase(40);
  tree3.print_tree();
  


  std::cout << "test find "	<< std::endl;
  std::cout << "find 1 " << tree2.find(1)->data << std::endl;
  std::cout << "find 2 " << tree2.find(2) << std::endl;
  std::cout << "find 3 " << tree2.find(15)->data << std::endl;

}