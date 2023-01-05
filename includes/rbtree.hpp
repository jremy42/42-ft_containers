
#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "node.hpp"
#include "pair.hpp"
#include <memory>
#include "binary_function.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

struct Trunk
{
    Trunk *prev;
    std::string str;
 
    Trunk(Trunk *prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

namespace ft
{
	template <class T, class Compare = ft::less<T> , class Alloc = std::allocator<T>, class Node = ft::Node<T> >
	class rbtree
	{
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef Compare key_compare;

		public:
			rbtree(void);
			rbtree(const rbtree &other);
			~rbtree();	
			rbtree &operator=(const rbtree &other);

			void insert(value_type data);
			void print_tree(void);
			void clear(void);
		private:
			Node *_root;
			Node *_nil;
			int _height;
			allocator_type alloc;
			key_compare comp;
			void insert_tree_preorder_mode(Node *root, Node *node);
			void showTrunks(Trunk *p);
			void printTreeWithTrunks(Node *root, Trunk *prev, bool isLeft);
			void rotate_left(Node *node);
			void rotate_right(Node *node);
			void insert_fixup(Node *node);
			void delete_fixup(Node *node);
			int get_height(Node *node);

	};


#include "rbtree.tpp"
};
#endif