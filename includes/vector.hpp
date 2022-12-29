#ifndef VECTOR_HPP
#define VECTOR_HPP

#define DEBUG 1
#include <memory>
#include <stdexcept>
#include <iostream>

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

			// Constructors
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector(const vector& x);

			// Destructor
			~vector();

			// Operators
			vector& operator=(const vector& x);
			
			// Iterators
			/* iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const; */
			// Capacity
			size_type size() const;
			size_type max_size() const;
			void resize(size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve(size_type n);
			
			// Element access
			reference operator[](size_type n);
			const_reference operator[](size_type n) const;
			reference at(size_type n);

			// Modifiers
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last);
			void assign(size_type n, const value_type& val);
			void push_back(const value_type& val);
			void pop_back();
			//void insert(iterator position, const value_type& val);
			//void insert(iterator position, size_type n, const value_type& val);
			//template <class InputIterator>
			//void insert(iterator position, InputIterator first, InputIterator last);
			//iterator erase(iterator position);
			//iterator erase(iterator first, iterator last);
			void swap(vector& x);
			void clear();
			//debug

		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _allocator;
	};
#include "vector.tpp"
};

#endif