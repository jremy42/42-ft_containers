#pragma once

#define DEBUG 1
#include <memory>
#include <cstddef>

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

	template <class Iterator>
	struct iterator_traits<Iterator*> {
		typedef std::ptrdiff_t difference_type;
		typedef Iterator value_type;
		typedef Iterator* pointer;
		typedef Iterator& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <class Iterator>
	struct iterator_traits<const Iterator*> {
		typedef std::ptrdiff_t difference_type;
		typedef Iterator value_type;
		typedef const Iterator* pointer;
		typedef const Iterator& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <class Category, class Iterator, class Distance = std::ptrdiff_t, class Pointer = Iterator*, class Reference = Iterator&>
	struct iterator {
		typedef Category iterator_category;
		typedef Iterator value_type;
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
		
		private:
			pointer _current;

		public:
			random_access_iterator() : _current() {}
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

			friend random_access_iterator operator+(difference_type n, const random_access_iterator &it) {
				random_access_iterator tmp(it);
				tmp._current += n;
				return tmp;
			}

			friend random_access_iterator operator-(difference_type n, const random_access_iterator &it) {
				random_access_iterator tmp(it);
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

			template <class U>
			random_access_iterator &operator=(const random_access_iterator<U> &other) {
				_current = other.base();
				return *this;
			}
	};

	//create reverse iterator
	template <class Iterator>
	class reverse_iterator : public ft::iterator<
									typename iterator_traits<Iterator>::iterator_category,
									typename iterator_traits<Iterator>::value_type,
									typename iterator_traits<Iterator>::difference_type,
									typename iterator_traits<Iterator>::pointer,
									typename iterator_traits<Iterator>::reference>
	{
		public:
			typedef Iterator 													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
		
		protected: // maybe private
			iterator_type _current;

		public:

			reverse_iterator() : _current() {}

			explicit reverse_iterator(iterator_type it) : _current(it) {}

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &other) : _current(other.base()) {}
			
			virtual ~reverse_iterator() {}

			iterator_type base() const { return _current; }
			
			operator reverse_iterator<const Iterator>() const { return reverse_iterator<const Iterator>(_current); }
			
			reverse_iterator &operator=(const reverse_iterator &other) {
				if (this != &other)
					_current = other.base();
				return *this;
			}	

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

			friend reverse_iterator operator+(difference_type n, const reverse_iterator &it)
			{ return it + n; }

			friend reverse_iterator operator-(difference_type n, const reverse_iterator &it)
			{ return it - n; }


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
			
			template <class U>
			reverse_iterator &operator=(const reverse_iterator<U> &other) {
				_current = other.base();
				return *this;
			}	
	};
};