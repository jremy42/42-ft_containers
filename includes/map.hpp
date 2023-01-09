#ifndef MAP_HPP
#define MAP_HPP

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

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public: 
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef ft::rbtree<ft::pair<const Key, T>, Compare, std::allocator<ft::Node<value_type> > > tree_type;
		typedef Compare key_compare;
		//value_compare is a binary predicate that takes two element keys as arguments and returns a bool.
		//typedef typename tree_type::key_compare value_compare;
		typedef Allocator allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		// Constructors
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
		map(const map& x);
		// Destructor
		~map();
		// Operators =
		map& operator=(const map& x);
		// get allocator
		allocator_type get_allocator() const;
		// element access
		mapped_type& operator[](const key_type& k);
		mapped_type& at(const key_type& k);
		const mapped_type& at(const key_type& k) const;

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
		size_type erase(const key_type& k);
		void erase(iterator first, iterator last);
		void swap(map& x);
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
	//value_compare value_comp() const;
		private :
			tree_type _tree;
			allocator_type _alloc;
			key_compare _comp;
			size_type _size;
			ft::Node<value_type> *_root;
			ft::Node<value_type> *_end;
	};
	#include "map.tpp"
};
#endif