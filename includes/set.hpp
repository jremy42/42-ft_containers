#ifndef SET_HPP
#define SET_HPP

#include <memory>
#include <stdexcept>
#include <iostream>
#include "iterator.hpp"
#include "is_integrale.hpp"
#include "enable_if.hpp"
#include "distance.hpp"
#include "binary_predicate.hpp"
#include "pair.hpp"
#include "rbtree.hpp"
#include "node_iterator.hpp"
#include "node.hpp"

namespace ft{

	template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator< Key> > 
	class set
	{
		public: 
		typedef Key key_type;
		typedef key_type value_type;
		typedef value_type mapped_type;
		typedef	value_type& reference;
		typedef const value_type& const_reference;
		typedef Compare key_compare;
		typedef key_compare value_compare;
		typedef Allocator allocator_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef typename ft::node_iterator<const value_type > iterator;
		typedef typename ft::node_iterator<const value_type > const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		typedef ft::rbtree<const value_type, value_compare, std::allocator<ft::Node<const value_type> > > tree_type;


		// Constructors
		explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
		set(const set& x);
		// Destructor
		~set();
		// Operators =
		set& operator=(const set& x);
		// get allocator
		allocator_type get_allocator() const;

		//iterators
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
		
		//capacity
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		//modifiers

		ft::pair<iterator,bool> insert(const value_type& val);
		iterator insert(iterator position, const value_type& val);
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
		void erase(iterator position);
		void erase(iterator first, iterator last);
		size_type erase(const key_type& k);
		void swap(set& x);
		void clear();

		//lookup
		size_type count(const key_type& k) const;
		iterator find(const key_type& k);
		const_iterator find(const key_type& k) const;
		ft::pair<iterator,iterator> equal_range(const key_type& k);
		ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
		iterator lower_bound(const key_type& k);
		const_iterator lower_bound(const key_type& k) const;
		iterator upper_bound(const key_type& k);
		const_iterator upper_bound(const key_type& k) const;

		// observers
		key_compare key_comp() const;
		value_compare value_comp() const;

		// print
		//void print(void);
		private :
			tree_type _tree;
			allocator_type _alloc;
			key_compare _comp;
	};
	//overload operators
	template <class Key, class Compare, class Allocator>
	bool operator==(const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs);
	
	template <class Key, class Compare, class Allocator>
	bool operator!=(const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs);
	
	template <class Key, class Compare, class Allocator>
	bool operator<(const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs);
	
	template <class Key, class Compare, class Allocator>
	bool operator<=(const set<Key, Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs);
	
	template <class Key, class Compare, class Allocator>
	bool operator>(const set<Key, Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs);
	
	template <class Key, class Compare, class Allocator>
	bool operator>=(const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs);
	
	template <class Key, class Compare, class Allocator>
	void swap(set<Key,Compare,Allocator>& x, set<Key,Compare,Allocator>& y);

	#include "set.tpp"
};

#endif