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
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef	value_type& reference;
		typedef const value_type& const_reference;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef typename ft::node_iterator<value_type > iterator;
		typedef typename ft::const_node_iterator<value_type > const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;

			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				value_compare& operator=(const value_compare& x)
				{
					comp = x.comp;
					return *this;
				}
				bool operator()(const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};
		typedef ft::rbtree<value_type, value_compare, std::allocator<ft::Node<value_type> > > tree_type;


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
		void erase(iterator first, iterator last);
		size_type erase(const key_type& k);
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
		value_compare value_comp() const;

		// print
		void print(void);
		private :
			tree_type _tree;
			allocator_type _alloc;
			key_compare _comp;
	};
	//overload operators
	template <class Key, class T, class Compare, class Allocator>
	bool operator==(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator!=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator<(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator<=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator>(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator>=(const map<Key,T,Compare,Allocator>& lhs, const map<Key,T,Compare,Allocator>& rhs);
	
	template <class Key, class T, class Compare, class Allocator>
	void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y);

	#include "map.tpp"
};

#endif