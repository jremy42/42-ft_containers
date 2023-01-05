#ifndef VECTOR_TPP
#define VECTOR_TPP

#ifndef VECTOR_HPP
# error "You must include vector.hpp before vector.tpp"
#endif

/* ********************************************
 * 	Constructors
 ******************************************** */

template <class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc)
	: _data(NULL), _size(0), _capacity(0), _allocator(alloc)
{
}

template <class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
	: _data(NULL), _size(0), _capacity(0), _allocator(alloc)
{
	reserve(n);
	for (size_type i = 0; i < n; i++)
		_allocator.construct(&_data[i], val);
	_size = n;
}


template <class T, class Alloc>
template <class InputIterator>
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
	: _data(NULL), _size(0), _capacity(0), _allocator(alloc)
{
	insert(begin(), first, last);
}

template <class T, class Alloc>
ft::vector<T, Alloc>::vector(const vector& lhs)
	: _data(NULL), _size(0), _capacity(0), _allocator(lhs._allocator)
{
	*this = lhs;
}

// surcharge operator=
template <class T, class Alloc>
ft::vector<T, Alloc>&
ft::vector<T, Alloc>::operator=(const vector& lhs)
{
	if (this != &lhs)
	{
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(&_data[i]);
		_allocator.deallocate(_data, _capacity);
		_size = lhs._size;
		_capacity = lhs._capacity;
		_allocator = lhs._allocator;
		_data = _allocator.allocate(_capacity); 
		for (size_type i = 0; i < _size; i++)
			_allocator.construct(&_data[i], lhs._data[i]);
	}
	return *this;
}

// to do 2 other constructors


/* ********************************************
 * 	Destructor
 ******************************************** */

template <class T, class Alloc>
ft::vector<T, Alloc>::~vector(void)
{
	clear();
	_allocator.deallocate(_data, _capacity);
}


/* ********************************************
 * 	Iterators
 ******************************************** */

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator
ft::vector<T, Alloc>::begin(void)
{
	return iterator(_data);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator
ft::vector<T, Alloc>::begin(void) const
{
	return const_iterator(_data);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator
ft::vector<T, Alloc>::end(void)
{
	return iterator(_data + _size);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator
ft::vector<T, Alloc>::end(void) const
{
	return const_iterator(_data + _size);
}

// Reverse iterator
template <class T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator
ft::vector<T, Alloc>::rbegin(void)
{
	return reverse_iterator(end());
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator
ft::vector<T, Alloc>::rbegin(void) const
{
	return const_reverse_iterator(end());
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator
ft::vector<T, Alloc>::rend(void)
{
	return reverse_iterator(begin());
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator
ft::vector<T, Alloc>::rend(void) const
{
	return const_reverse_iterator(begin());
} 

/* ********************************************
 * 	Capacity
 ******************************************** */

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type
ft::vector<T, Alloc>::size(void) const
{
	return _size;
}


template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type
ft::vector<T, Alloc>::max_size(void) const
{
	return _allocator.max_size();
}

template <class T, class Alloc>
void
ft::vector<T, Alloc>::resize(size_type n, value_type val)
{
	if (n > _size)
	{
		if (n > _capacity)
			reserve(n);
		for (size_type i = _size; i < n; i++)
			_allocator.construct(&_data[i], val);
	}
	else if (n < _size)
	{
		for (size_type i = n; i < _size; i++)
			_allocator.destroy(&_data[i]);
	}
	_size = n;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type
ft::vector<T, Alloc>::capacity(void) const
{
	return _capacity;
}

template <class T, class Alloc>
bool
ft::vector<T, Alloc>::empty(void) const
{
	return (_size == 0);
}


template <class T, class Alloc>
void
ft::vector<T, Alloc>::reserve(size_type n)
{
	if (n > max_size())
		throw std::length_error("vector::reserve");

	if (n > _capacity)
	{
		try
		{
			pointer tmp = _allocator.allocate(n);
				for (size_type i = 0; i < _size; i++)
			{
				_allocator.construct(&tmp[i], _data[i]);
				_allocator.destroy(&_data[i]);
			}
			_allocator.deallocate(_data, _capacity);
			_data = tmp;
			_capacity = n;
		}
		catch(const std::bad_alloc& e)
		{
			std::cerr << "bad alloc in ft vector" << std::endl;
			throw;
		}
	}
}

/* ********************************************
 * 	Element access
 ******************************************** */

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference
ft::vector<T, Alloc>::operator[](size_type n)
{
	return _data[n];
}
template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference
ft::vector<T, Alloc>::operator[](size_type n) const
{
	return _data[n];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference
ft::vector<T, Alloc>::at(size_type n)
{
	if (n >= _size)
		throw std::out_of_range("vector::at");
	return _data[n];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference
ft::vector<T, Alloc>::at(size_type n) const
{
	if (n >= _size)
		throw std::out_of_range("vector::at");
	return _data[n];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference
ft::vector<T, Alloc>::front(void)
{
	return _data[0];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference
ft::vector<T, Alloc>::front(void) const
{
	return _data[0];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::reference
ft::vector<T, Alloc>::back(void)
{
	if (_size == 0)
		throw std::out_of_range("vector::back");
	return _data[_size - 1];
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::const_reference
ft::vector<T, Alloc>::back(void) const
{
	if (_size == 0)
		throw std::out_of_range("vector::back");
	return _data[_size - 1];
}

/* ********************************************
 * 		Modifiers
 ******************************************** */

// Assign with check if iterator tag is random access
template <class T, class Alloc>
template <class InputIterator>
void
ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
{
	typedef typename ft::iterator_traits<InputIterator>::iterator_category category;
	assign_range(first, last, category());
}

template <class T, class Alloc>
template <class InputIterator>
void
ft::vector<T, Alloc>::assign_range(InputIterator first, InputIterator last, std::forward_iterator_tag)
{
	clear();
	insert(begin(), first, last);
}

template <class T, class Alloc>
template <class InputIterator>
void
ft::vector<T, Alloc>::assign_range(InputIterator first, InputIterator last, std::input_iterator_tag )
{
	clear();
	while (first != last)
	{
		push_back(*first);
		first++;
	}
}


template <class T, class Alloc>
void
ft::vector<T, Alloc>::assign(size_type n, const value_type& val)
{
	clear();
	insert(begin(), n, val);
}

template <class T, class Alloc>
void
ft::vector<T, Alloc>::push_back(const value_type& val)
{
	if(_size == _capacity)
	{
		if (_capacity == 0)
			reserve(1);
		else
			reserve(_capacity * 2);
	}
	_allocator.construct(&_data[_size], val);
	_size++;
}


template <class T, class Alloc>
void
ft::vector<T, Alloc>::pop_back(void)
{
	if (_size > 0)
	{
		_allocator.destroy(&_data[_size - 1]);
		_size--;
	}
}

// insert
template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator
ft::vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	difference_type pos_ret = ft::distance(begin(), position);
	insert(position, 1, val);
	return (iterator(&_data[pos_ret]));
}

template <class T, class Alloc>
void
ft::vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	difference_type pos = ft::distance(begin(), position);
	difference_type begin_end = ft::distance(begin(), end());
	difference_type position_end = ft::distance(position, end());
	if (n == 0)
		return;
	if (_size + n <= _capacity);
	else if (n + _size > _capacity * 2)
		reserve((n + _size));
	else
		reserve(_capacity * 2);
	for (difference_type i = 1; i <= position_end; i++) {
		_allocator.construct(&_data[begin_end + n - i], _data[begin_end - i]);
		_allocator.destroy(&_data[begin_end - i]);
	}
	for (size_type i = 0; i < n; i++) {
		_allocator.construct(&_data[pos + i], val);
	}
	_size += n;
}

template <class T, class Alloc>
template <class InputIterator>
void
ft::vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
{
	typedef typename ft::iterator_traits<InputIterator>::iterator_category category;
	insert_range(position, first, last, category());
}

template <class T, class Alloc>
template <class InputIterator>
void
ft::vector<T, Alloc>::insert_range(iterator position, InputIterator first, InputIterator last, std::forward_iterator_tag)
{
	difference_type pos = ft::distance(begin(), position);
	difference_type begin_end = ft::distance(begin(), end());
	difference_type position_end = ft::distance(position, end());
	difference_type n = ft::distance(first, last);
	if (n == 0)
		return;
	if (_size + n <= _capacity);
	else if (n + _size > _capacity * 2)
		reserve((n + _size));
	else
		reserve(_capacity * 2);
	for (difference_type i = 1; i <= position_end; i++) {
		_allocator.construct(&_data[begin_end + n - i], _data[begin_end - i]);
		_allocator.destroy(&_data[begin_end - i]);
	}
	for (difference_type i = 0; i < n; i++) {
		_allocator.construct(&_data[pos + i], *first);
		first++;
	}
	_size += n;
}

template <class T, class Alloc>
template <class InputIterator>
void
ft::vector<T, Alloc>::insert_range(iterator position, InputIterator first, InputIterator last, std::input_iterator_tag)
{
	difference_type pos = ft::distance(begin(), position);
	vector<value_type> tmp;

	tmp.insert(tmp.begin(), begin(), begin() + pos);
	for (InputIterator it = first; it != last; it++)
		tmp.push_back(*it);
	tmp.insert(tmp.end(), begin() + pos, end());
	*this = tmp;
}



template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator
ft::vector<T, Alloc>::erase(iterator position)
{
	size_type pos = ft::distance(begin(), position);
	for (size_type i = pos; i < _size - 1; i++)
	{
		_data[i] = _data[i + 1];
	}
	_allocator.destroy(&_data[_size - 1]);
	_size--;
	return begin() + pos;
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::iterator
ft::vector<T, Alloc>::erase(iterator first, iterator last)
{
	size_type pos = ft::distance(begin(), first);
	size_type n = ft::distance(first, last);
	for (size_type i = pos; i < _size - n; i++)
	{
		_data[i] = _data[i + n];
	}
	for (size_type i = 0; i < n; i++)
	{
		_allocator.destroy(&_data[_size - 1 - i]);
	}
	_size -= n;
	return begin() + pos;
}

template <class T, class Alloc>
void
ft::vector<T, Alloc>::swap(vector& x)
{
	pointer tmp_data = _data;
	size_type tmp_size = _size;
	size_type tmp_capacity = _capacity;
	allocator_type tmp_allocator = _allocator;
	_data = x._data;
	_size = x._size;
	_capacity = x._capacity;
	_allocator = x._allocator;
	x._data = tmp_data;
	x._size = tmp_size;
	x._capacity = tmp_capacity;
	x._allocator = tmp_allocator;

}

template <class T, class Alloc>
void
ft::vector<T, Alloc>::clear(void)
{
	for (size_type i = 0; i < _size; i++)
	{
		_allocator.destroy(&_data[i]);
	}
	_size = 0;
}

// allocator
template <class T, class Alloc>
typename ft::vector<T, Alloc>::allocator_type
ft::vector<T, Alloc>::get_allocator(void) const
{
	return _allocator;
}

/* ********************************************
 * 			Non-member function overloads
 ******************************************** */

template <class T, class Alloc>
bool
operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool
operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool
operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool
operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool
operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	return rhs < lhs;
}

template <class T, class Alloc>
bool
operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	return !(lhs < rhs);
}

template <class T, class Alloc>
void
swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
{
	x.swap(y);
}


template <class T, class Alloc>
std::string
ft::vector<T, Alloc>::leon(void) const
{
	return std::string("0ZZZZZRRA§AAAAAAAAAAAAAAAAAAAAiiiiiiiiiiivf cggfffjufccccccccbujvcjjjjjjjjjjjjjj  ttttttttttttttttttt cegxxffffxxxxxgggggggggg cvtrrrrrnhhhhnhffffffffffffffffffffffffffffhnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn                          cgggggggggggggg~~~~~~~~~~~~~~~~~~~            zzzz§§§§§§§§00000000000000000000000\n00000000000000000000000000000000000000000000000000xxxxxxxxx≈≈≈xxxxxdd");
}

#endif