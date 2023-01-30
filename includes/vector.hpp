#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <iostream>
#include "iterator.hpp"
#include "is_integrale.hpp"
#include "enable_if.hpp"
#include "distance.hpp"
#include "lexicographical_compare.hpp"

namespace ft{

	template <class T, class Alloc = std::allocator<T> >
	class vector{

		public:
			typedef T value_type;
			typedef Alloc allocator_type;
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
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			vector(const vector& x);

			// Destructor
			~vector();

			// Operators
			vector& operator=(const vector& x);
			
			//Iterators
			iterator begin();
			iterator end();
			const_iterator begin() const;
			const_iterator end() const;
			reverse_iterator rbegin();
			reverse_iterator rend();
			const_reverse_iterator rbegin() const;
			const_reverse_iterator rend() const;
			 
			// Capacity
			size_type size() const;
			size_type max_size() const;
			void resize(size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty(void) const;
			void reserve(size_type n);
			
			// Element access
			reference operator[](size_type n);
			const_reference operator[](size_type n) const;
			reference at(size_type n);
			const_reference at(size_type n) const;
			reference front(void);
			const_reference front(void) const;
			reference back(void);
			const_reference back(void) const;


			// Modifiers
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			void assign(size_type n, const value_type& val);
			void push_back(const value_type& val);
			void pop_back();
			iterator insert(iterator position, const value_type& val);
			void insert(iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			iterator erase(iterator position);
			iterator erase(iterator first, iterator last);
			void swap(vector& x);
			void clear();
			// Allocator
			allocator_type get_allocator() const;

		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _allocator;
			template <class InputIterator>
			void assign_range(InputIterator first, InputIterator last, std::forward_iterator_tag);
			template <class InputIterator>
			void assign_range(InputIterator first, InputIterator last, std::input_iterator_tag);
			template <class InputIterator>
			void insert_range(iterator position, InputIterator first, InputIterator last, std::forward_iterator_tag);
			template <class InputIterator>
			void insert_range(iterator position, InputIterator first, InputIterator last, std::input_iterator_tag);
	};

	// overload operators
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	
	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
	
#include "vector.tpp"
};

#endif