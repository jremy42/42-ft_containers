#pragma once

#define DEBUG 1
#include <memory>

namespace ft {

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};

	template <class T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
		
		protected:
			pointer _current;

		public:
			random_access_iterator() : _current(nullptr) {}
			explicit random_access_iterator(pointer ptr) : _current(ptr) {}
			random_access_iterator(const random_access_iterator &other) : _current(other._current) {}
			virtual ~random_access_iterator() {}
			random_access_iterator &operator=(const random_access_iterator &other) {
				if (this != &other)
					_current = other._current;
				return *this;
			}
			operator random_access_iterator<const T>() const { return random_access_iterator<const T>(_current); }
			pointer base() const { return _current; }
			reference operator*() const { return (*_current); }
			pointer operator->() const { return _current; }
			random_access_iterator &operator++() {
				++_current;
				return *this;
			}
			random_access_iterator operator++(int) {
				random_access_iterator tmp(*this);
				++_current;
				return tmp;
			}
			random_access_iterator &operator--() {
				--_current;
				return *this;
			}
			random_access_iterator operator--(int) {
				random_access_iterator tmp(*this);
				--_current;
				return tmp;
			}
			random_access_iterator operator+(difference_type n) const {
				random_access_iterator tmp(*this);
				tmp._current += n;
				return tmp;
			}
			random_access_iterator operator-(difference_type n) const {
				random_access_iterator tmp(*this);
				tmp._current -= n;
				return tmp;
			}
			random_access_iterator &operator+=(difference_type n) {
				_current += n;
				return *this;
			}
			random_access_iterator &operator-=(difference_type n) {
				_current -= n;
				return *this;
			}
			reference operator[](difference_type n) const { return _current[n]; }
			friend bool operator==(const random_access_iterator &lhs, const random_access_iterator &rhs) { return lhs._current == rhs._current; } // base() is a protected member
			friend bool operator!=(const random_access_iterator &lhs, const random_access_iterator &rhs) { return lhs._current != rhs._current; }
			friend bool operator<(const random_access_iterator &lhs, const random_access_iterator &rhs) { return lhs._current < rhs._current; }
			friend bool operator<=(const random_access_iterator &lhs, const random_access_iterator &rhs) { return lhs._current <= rhs._current; }
			friend bool operator>(const random_access_iterator &lhs, const random_access_iterator &rhs) { return lhs._current > rhs._current; }
			friend bool operator>=(const random_access_iterator &lhs, const random_access_iterator &rhs) { return lhs._current >= rhs._current; }

	};
	//create reverse iterator
	template <class T>
	class reverse_iterator : public iterator<typename iterator_traits<T>::iterator_category, typename iterator_traits<T>::value_type, typename iterator_traits<T>::difference_type, typename iterator_traits<T>::pointer, typename iterator_traits<T>::reference>
	{
		public:
			typedef T iterator_type;
			typedef typename ft::iterator_traits<T>::value_type value_type;
			typedef typename ft::iterator_traits<T>::difference_type difference_type;
			typedef typename ft::iterator_traits<T>::pointer pointer;
			typedef typename ft::iterator_traits<T>::reference reference;
			typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
		
		protected:
			iterator_type _current;

		public:
			reverse_iterator() : _current() {}
			explicit reverse_iterator(iterator_type it) : _current(it) {}
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &other) : _current(other._current) {}
			virtual ~reverse_iterator() {}
			reverse_iterator &operator=(const reverse_iterator &other) {
				if (this != &other)
					_current = other._current;
				return *this;
			}
			iterator_type base() const { return _current; }
			reference operator*() const {
				iterator_type tmp = _current;
				return *--tmp;
			}
			pointer operator->() const { return &(operator*()); }
			reverse_iterator &operator++() {
				--_current;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				--_current;
				return tmp;
			}
			reverse_iterator &operator--() {
				++_current;
				return *this;
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				++_current;
				return tmp;
			}
			reverse_iterator operator+(difference_type n) const {
				reverse_iterator tmp(*this);
				tmp._current -= n;
				return tmp;
			}
			reverse_iterator operator-(difference_type n) const {
				reverse_iterator tmp(*this);
				tmp._current += n;
				return tmp;
			}
			reverse_iterator &operator+=(difference_type n) {
				_current -= n;
				return *this;
			}
			reverse_iterator &operator-=(difference_type n) {
				_current += n;
				return *this;
			}
			reference operator[](difference_type n) const { return *(*this + n); }
			friend bool operator==(const reverse_iterator &lhs, const reverse_iterator &rhs) { return lhs._current == rhs._current; }
			friend bool operator!=(const reverse_iterator &lhs, const reverse_iterator &rhs) { return lhs._current != rhs._current; }
			friend bool operator<(const reverse_iterator &lhs, const reverse_iterator &rhs) { return lhs._current > rhs._current; }
			friend bool operator<=(const reverse_iterator &lhs, const reverse_iterator &rhs) { return lhs._current >= rhs._current; }
			friend bool operator>(const reverse_iterator &lhs, const reverse_iterator &rhs) { return lhs._current < rhs._current; }
			friend bool operator>=(const reverse_iterator &lhs, const reverse_iterator &rhs) { return lhs._current <= rhs._current; }
	};
};