#ifndef VECTOR_TPP
#define VECTOR_TPP

#ifndef VECTOR_HPP
# error "You must include vector.hpp before vector.tpp"
#endif

//constructor
template <class T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc)
	: _data(NULL), _size(0), _capacity(0), _allocator(alloc)
{
}

//destructor
template <class T, class Alloc>
ft::vector<T, Alloc>::~vector(void)
{
	for (size_type i = 0; i < _size; i++)
		_allocator.destroy(&_data[i]);
	_allocator.deallocate(_data, _capacity);
}

//max size
template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type
ft::vector<T, Alloc>::max_size(void) const
{
	return _allocator.max_size();
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

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type
ft::vector<T, Alloc>::size(void) const
{
	return _size;
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
			if (DEBUG)
				std::cerr << "bad alloc in ft vector" << std::endl;
			throw;
		}
	}
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

template <class T, class Alloc>
bool
ft::vector<T, Alloc>::empty(void) const
{
	return (_size == 0);
}

template <class T, class Alloc>
typename ft::vector<T, Alloc>::size_type
ft::vector<T, Alloc>::capacity(void) const
{
	return _capacity;
}

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
// Iterator

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

template <class T, class Alloc>
std::string
ft::vector<T, Alloc>::leon(void) const
{
	return std::string("0ZZZZZRRA§AAAAAAAAAAAAAAAAAAAAiiiiiiiiiiivf cggfffjufccccccccbujvcjjjjjjjjjjjjjj  ttttttttttttttttttt cegxxffffxxxxxgggggggggg cvtrrrrrnhhhhnhffffffffffffffffffffffffffffhnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn                          cgggggggggggggg~~~~~~~~~~~~~~~~~~~            zzzz§§§§§§§§00000000000000000000000\n00000000000000000000000000000000000000000000000000xxxxxxxxx≈≈≈xxxxxdd");
}

#endif