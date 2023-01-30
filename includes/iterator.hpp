#pragma once

#include <memory>
#include <cstddef>

namespace ft {

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
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class Iterator>
	struct iterator_traits<const Iterator*> {
		typedef std::ptrdiff_t difference_type;
		typedef Iterator value_type;
		typedef const Iterator* pointer;
		typedef const Iterator& reference;
		typedef std::random_access_iterator_tag iterator_category;
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
	class random_access_iterator : public iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
		
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

			friend difference_type operator-(difference_type n, const random_access_iterator &it) {
				return n - it._current;
			}

			friend difference_type operator-(const ft::random_access_iterator<value_type> &lhs, const ft::random_access_iterator<value_type> &rhs) {
				return lhs.base() - rhs.base();
			}

			friend ft::random_access_iterator<value_type> operator+(const ft::random_access_iterator<value_type> &lhs, const ft::random_access_iterator<value_type> &rhs) {
				return ft::random_access_iterator<value_type>(lhs.base() + rhs.base());
			}


			random_access_iterator &operator+=(difference_type n) {
				_current += n;
				return *this;
			}

			random_access_iterator &operator-=(difference_type n) {
				_current -= n;
				return *this;
			}

			reference operator[](difference_type n) const { return *(*this + n); }
	
			template <class U>
			random_access_iterator &operator=(const ft::random_access_iterator<U> &other) {
				_current = other.base();
				return *this;
			}
	};

			template <class Left, class Right>
			bool operator==(const ft::random_access_iterator<Left> &lhs, const ft::random_access_iterator<Right> &rhs) { return lhs.base() == rhs.base(); }
			template <class Left, class Right>
			bool operator!=(const ft::random_access_iterator<Left> &lhs, const ft::random_access_iterator<Right> &rhs) { return lhs.base() != rhs.base(); }
			template <class Left, class Right>
			bool operator<(const ft::random_access_iterator<Left> &lhs, const ft::random_access_iterator<Right> &rhs) { return lhs.base() < rhs.base(); }
			template <class Left, class Right>
			bool operator<=(const ft::random_access_iterator<Left> &lhs, const ft::random_access_iterator<Right> &rhs) { return lhs.base() <= rhs.base(); }
			template <class Left, class Right>
			bool operator>(const ft::random_access_iterator<Left> &lhs, const ft::random_access_iterator<Right> &rhs) { return lhs.base() > rhs.base(); }
			template <class Left, class Right>
			bool operator>=(const ft::random_access_iterator<Left> &lhs, const ft::random_access_iterator<Right> &rhs) { return lhs.base() >= rhs.base(); }

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
		
		private: // maybe private
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
			
			template <class U>
			reverse_iterator &operator=(const reverse_iterator<U> &other) {
				_current = other.base();
				return *this;
			}	
	};

			template <class Left, class Right>
			bool operator==(const ft::reverse_iterator<Left> &lhs, const ft::reverse_iterator<Right> &rhs) { return lhs.base() == rhs.base(); }
			template <class Left, class Right>
			bool operator!=(const ft::reverse_iterator<Left> &lhs, const ft::reverse_iterator<Right> &rhs) { return lhs.base() != rhs.base(); }
			template <class Left, class Right>
			bool operator<(const ft::reverse_iterator<Left> &lhs, const ft::reverse_iterator<Right> &rhs) { return (lhs.base() > rhs.base()); }
			template <class Left, class Right>
			bool operator<=(const ft::reverse_iterator<Left> &lhs, const ft::reverse_iterator<Right> &rhs) { return (lhs.base() >= rhs.base()); }
			template <class Left, class Right>
			bool operator>(const ft::reverse_iterator<Left> &lhs, const ft::reverse_iterator<Right> &rhs) { return (lhs.base() < rhs.base()); }
			template <class Left, class Right>
			bool operator>=(const ft::reverse_iterator<Left> &lhs, const ft::reverse_iterator<Right> &rhs) { return (lhs.base() <= rhs.base()); }

			template <class Iter1, class Iter2>
			ft::reverse_iterator<Iter1> operator+(typename ft::reverse_iterator<Iter1>::difference_type n, const ft::reverse_iterator<Iter2> &it) { return it + n; }
			template <class Iter1, class Iter2>
			typename ft::reverse_iterator<Iter1>::difference_type operator-(const ft::reverse_iterator<Iter1> &lhs, const ft::reverse_iterator<Iter2> &rhs) { return rhs.base() - lhs.base(); }

			template <class Iterator>
			ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator> &it) { return it + n; }

			template <class Iterator>
			ft::reverse_iterator<Iterator> operator-(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator> &it) { return it - n; }
};