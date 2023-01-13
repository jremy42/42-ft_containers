#ifndef SET_TPP
#define SET_TPP

#ifndef SET_HPP
# error "You must include set.hpp before set.tpp"
#endif

/* ********************************************
 * 	Constructors
 ******************************************** */

template <class Key, class Compare, class Alloc>
ft::set<Key, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc) : _tree(value_compare(comp))
{
	_alloc = alloc;
}

template <class Key, class Compare, class Alloc>
template <class InputIterator>
ft::set<Key, Compare, Alloc>::set(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) : _tree(value_compare(comp))
{
	//std::cout << "constructor with iterators called" << std::endl;
	//std::cout << first->first << std::endl;
	_alloc = alloc;
	for (; first != last; ++first)
		_tree.insert(*first);
}

template <class Key, class Compare, class Alloc>
ft::set<Key, Compare, Alloc>::set(const set& other) : _tree(value_compare(other._comp))
{
	_alloc = other._alloc;
	_comp = other._comp;	
	for (const_iterator it = other.begin(); it != other.end(); ++it)
		_tree.insert(*it);
}

/* ********************************************
 * 	Destructor
 ******************************************** */

template <class Key, class Compare, class Alloc>
ft::set<Key, Compare, Alloc>::~set()
{}

/* ********************************************
 * 	Operators =
 ******************************************** */

template <class Key, class Compare, class Alloc>
ft::set<Key, Compare, Alloc>& ft::set<Key, Compare, Alloc>::operator=(const set& x)
{
	if (this == &x)
		return *this;
	_tree.clear();
	for (const_iterator it = x.begin(); it != x.end(); ++it)
		_tree.insert(*it);
	return *this;
}

/* ********************************************
 * 	get allocator
 ******************************************** */
template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::allocator_type ft::set<Key, Compare, Alloc>::get_allocator() const
{
	return _tree.get_allocator();
}

/* ********************************************
 * 	element access
 ******************************************** */
template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::mapped_type& ft::set<Key, Compare, Alloc>::operator[](const key_type& k)
{
	//std::cout << "operator[] called" << std::endl;
	iterator it;
	if (count(k))
		it = find(k);
	else
		it = insert(value_type(k, mapped_type())).first;
	return it->second;
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::mapped_type& ft::set<Key, Compare, Alloc>::at(const key_type& k)
{
	iterator it;
	if (count(k))
		it = find(k);
	else
		throw std::out_of_range("set::at");
	return it->second;
}

template <class Key, class Compare, class Alloc>
const typename ft::set<Key, Compare, Alloc>::mapped_type& ft::set<Key, Compare, Alloc>::at(const key_type& k) const
{
	const_iterator it;
	if (count(k))
		it = find(k);
	else
		throw std::out_of_range("set::at");
	return it->second;
}

/* ********************************************
 * 	iterators
 ******************************************** */

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::begin()
{
	return iterator(_tree.getMin(), _tree.getNil(), _tree.getRoot());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_iterator ft::set<Key, Compare, Alloc>::begin() const
{
	return const_iterator(_tree.getMin(), _tree.getNil(), _tree.getRoot());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::end()
{
	return iterator(_tree.getNil(), _tree.getNil(), _tree.getRoot());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_iterator ft::set<Key, Compare, Alloc>::end() const
{
	return const_iterator(_tree.getNil(), _tree.getNil(), _tree.getRoot());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::reverse_iterator ft::set<Key, Compare, Alloc>::rbegin()
{
	return reverse_iterator(end());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_reverse_iterator ft::set<Key, Compare, Alloc>::rbegin() const
{
	return const_reverse_iterator(end());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::reverse_iterator ft::set<Key, Compare, Alloc>::rend()
{
	return reverse_iterator(begin());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_reverse_iterator ft::set<Key, Compare, Alloc>::rend() const
{
	return const_reverse_iterator(begin());
}

/* ********************************************
 * 	capacity
 ******************************************** */

template <class Key, class Compare, class Alloc>
bool ft::set<Key, Compare, Alloc>::empty() const
{
	return _tree.empty();
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::size() const
{
	return _tree.size();
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::max_size() const
{
	return _tree.max_size();
}

/* ********************************************
 * 	modifier
 ******************************************** */
template <class Key, class Compare, class Alloc>
ft::pair<typename ft::set<Key, Compare, Alloc>::iterator, bool> ft::set<Key, Compare, Alloc>::insert(const value_type& val)
{
	if (_tree.find(val))
		return ft::make_pair(iterator(_tree.find(val), _tree.getNil(), _tree.getRoot()), false);
	else
		return ft::make_pair(iterator(_tree.insert(val), _tree.getNil(), _tree.getRoot()), true);
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	(void)position;
	return insert(val).first;
}
// insert

template <class  Key, class Compare, class Alloc>
template <class InputIterator>
void ft::set<Key, Compare, Alloc>::insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
{
	for (; first != last; ++first)
		insert(*first);
}

template<class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::erase(iterator position)
{
	//std::cout << _tree.getRoot() << std::endl;
	_tree.erase(*position);
	//std::cout << _tree.getRoot() << std::endl;
}

template<class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::erase(iterator first, iterator last)
{
	while ( first != last)
	{
		iterator tmp = first;
		++first;
		_tree.erase(*tmp);
	}
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::erase(const key_type& k)
{
	if (_tree.find(k))
	{
		_tree.erase(k);
		return 1;
	}
	else
		return 0;
}

template <class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::swap(set& other)
{
	Compare tmp_key = _comp;
	_comp = other._comp;
	other._comp = tmp_key;
	allocator_type tmp_alloc = _alloc;
	_alloc = other._alloc;
	other._alloc = tmp_alloc;
	_tree.swap(other._tree);
}



template <class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::clear()
{
	_tree.clear();
}

/* ********************************************
 * 	lookup
 ******************************************** */

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::count(const key_type& k) const
{
	if (_tree.find(k))
		return 1;
	else
		return 0;
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::find(const key_type& k)
{
	if (_tree.find(k))
		return iterator(_tree.find(k), _tree.getNil(), _tree.getRoot());
	else
		return end();
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_iterator ft::set<Key, Compare, Alloc>::find(const key_type& k) const
{
if (_tree.find(k))
		return iterator(_tree.find(k), _tree.getNil(), _tree.getRoot());
	else
		return end();
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::lower_bound(const key_type& k)
{
	return iterator(_tree.lower_bound(k), _tree.getNil(), _tree.getRoot());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_iterator ft::set<Key, Compare, Alloc>::lower_bound(const key_type& k) const
{
	return const_iterator(_tree.lower_bound(k), _tree.getNil(), _tree.getRoot());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::upper_bound(const key_type& k)
{
	return iterator(_tree.upper_bound(k), _tree.getNil(), _tree.getRoot());
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_iterator ft::set<Key, Compare, Alloc>::upper_bound(const key_type& k) const
{
	return const_iterator(_tree.upper_bound(k), _tree.getNil(), _tree.getRoot());
}

template <class Key, class Compare, class Alloc>
ft::pair<typename ft::set<Key, Compare, Alloc>::iterator, typename ft::set<Key, Compare, Alloc>::iterator> ft::set<Key, Compare, Alloc>::equal_range(const key_type& k)
{
	return ft::make_pair(lower_bound(k), upper_bound(k));
}

template <class Key, class Compare, class Alloc>
ft::pair<typename ft::set<Key, Compare, Alloc>::const_iterator, typename ft::set<Key, Compare, Alloc>::const_iterator> ft::set<Key, Compare, Alloc>::equal_range(const key_type& k) const
{
	return ft::make_pair(lower_bound(k), upper_bound(k));
}

/* ********************************************
 * observer
 ******************************************** */
template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::key_compare ft::set<Key, Compare, Alloc>::key_comp() const
{
	return _comp;
}

template <class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::value_compare ft::set<Key, Compare, Alloc>::value_comp() const
{
	return value_compare(_comp);
}


/* ********************************************
 * print
 ******************************************** */

template <class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::print(void)
{
	_tree.print_tree();
}

/* ********************************************
 * 			Non-member function overloads
 ******************************************** */

template <class Key, class Compare, class Alloc>
bool operator==(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class Compare, class Alloc>
bool operator!=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{
	return !(lhs == rhs);
}

template <class Key, class Compare, class Alloc>
bool operator<(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class Compare, class Alloc>
bool operator<=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{
	return !(rhs < lhs);
}

template <class Key, class Compare, class Alloc>
bool operator>(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{
	return rhs < lhs;
}

template <class Key, class Compare, class Alloc>
bool operator>=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
{
	return !(lhs < rhs);
}

template <class Key, class Compare, class Alloc>
void swap(ft::set<Key, Compare, Alloc>& x, ft::set<Key, Compare, Alloc>& y)
{
	x.swap(y);
}


#endif