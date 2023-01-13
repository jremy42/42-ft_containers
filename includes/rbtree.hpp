
#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "node.hpp"
#include "pair.hpp"
#include <memory>
#include "binary_predicate.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "node_iterator.hpp"

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
	template <class T, class Compare, class Alloc = std::allocator<ft::Node<T> >, class Node = ft::Node<T> >
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
		typedef ft::node_iterator<value_type> iterator;

		public: 
			rbtree(void);
			rbtree(const key_compare &comp = key_compare());
			//rbtree(const rbtree &other);
			~rbtree();	
			//rbtree &operator=(const rbtree &other);
			
			//lookup
			void print_tree(void);
			int size(void) const;
			pointer find(const value_type data) const;
			bool is_valid_tree(void); // deprecated
			bool check_black_balanced(pointer node);
			bool empty(void) const;
			size_type max_size(void) const;


			// modifier
			void clear(void);
			pointer insert(const value_type data);
			bool erase(const value_type data);
			void swap(rbtree &other);

			// get
			pointer getRoot(void) const;
			pointer getNil(void) const;
			pointer getMin(void) const;
			pointer getMax(void) const;

			//lookup
			pointer lower_bound(const value_type data) const;
			pointer upper_bound(const value_type data) const;

		private:
			pointer _root;
			pointer _nil;
			allocator_type _alloc;
			key_compare _comp;
			//size_type _size;

			// insert functions
			void _insert_tree_preorder_mode(pointer root, pointer node);
			void _rotate_left(pointer node);
			void _rotate_right(pointer node);
			void _insert_fixup(pointer node);
			void _delete_fixup(pointer node);
			int _get_height(pointer node);
			void _transplant(pointer node1, pointer node2);
			// print functions
			void _showTrunks(Trunk *p);
			void _printTreeWithTrunks(pointer root, Trunk *prev, bool isLeft);
			void _clear(pointer node);
			pointer _find(pointer node, const value_type data) const;
			void	_erase(pointer node);
			pointer _findMin(pointer node) const;
			pointer _findMax(pointer node) const;
			bool	_is_valid_tree(pointer node);
			bool	_is_equilibrated(pointer node);
			int		_depthMin(pointer node, int depth);
			int		_depthMax(pointer node, int depth);
			int 	_depthBlack(pointer node);
			int		_getSize(pointer node) const;
			pointer _lower_bound(pointer node, const value_type data) const;
			pointer _upper_bound(pointer node, const value_type data) const;
	};


#include "rbtree.tpp"
};
#endif
