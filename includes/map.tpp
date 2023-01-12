#ifndef MAP_TPP
#define MAP_TPP

#ifndef MAP_HPP
# error "You must include map.hpp before map.tpp"
#endif

/* ********************************************
 * 	Constructors
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) : _tree(value_compare(comp))
{
	_alloc = alloc;
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
ft::map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) : _tree(value_compare(comp))
{
	//std::cout << "constructor with iterators called" << std::endl;
	//std::cout << first->first << std::endl;
	_alloc = alloc;
	for (; first != last; ++first)
		_tree.insert(*first);
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const map& other) : _tree(value_compare(other._comp))
{
	_alloc = other._alloc;
	_comp = other._comp;	
	for (const_iterator it = other.begin(); it != other.end(); ++it)
		_tree.insert(*it);
}

/* ********************************************
 * 	Destructor
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map()
{}

/* ********************************************
 * 	Operators =
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>& ft::map<Key, T, Compare, Alloc>::operator=(const map& x)
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
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::allocator_type ft::map<Key, T, Compare, Alloc>::get_allocator() const
{
	return _tree.get_allocator();
}

/* ********************************************
 * 	element access
 ******************************************** */
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type& ft::map<Key, T, Compare, Alloc>::operator[](const key_type& k)
{
	//std::cout << "operator[] called" << std::endl;
	iterator it;
	if (count(k))
		it = find(k);
	else
		it = insert(value_type(k, mapped_type())).first;
	return it->second;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type& ft::map<Key, T, Compare, Alloc>::at(const key_type& k)
{
	iterator it;
	if (count(k))
		it = find(k);
	else
		throw std::out_of_range("map::at");
	return it->second;
}

template <class Key, class T, class Compare, class Alloc>
const typename ft::map<Key, T, Compare, Alloc>::mapped_type& ft::map<Key, T, Compare, Alloc>::at(const key_type& k) const
{
	const_iterator it;
	if (count(k))
		it = find(k);
	else
		throw std::out_of_range("map::at");
	return it->second;
}

/* ********************************************
 * 	iterators
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::begin()
{
	return iterator(_tree.getMin(), _tree.getNil(), _tree.getRoot());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::begin() const
{
	return const_iterator(_tree.getMin(), _tree.getNil(), _tree.getRoot());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::end()
{
	return iterator(_tree.getNil(), _tree.getNil(), _tree.getRoot());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::end() const
{
	return const_iterator(_tree.getNil(), _tree.getNil(), _tree.getRoot());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rbegin()
{
	return reverse_iterator(end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rbegin() const
{
	return const_reverse_iterator(end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rend()
{
	return reverse_iterator(begin());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rend() const
{
	return const_reverse_iterator(begin());
}

/* ********************************************
 * 	capacity
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
bool ft::map<Key, T, Compare, Alloc>::empty() const
{
	return _tree.empty();
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::size() const
{
	return _tree.size();
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::max_size() const
{
	return _tree.max_size();
}

/* ********************************************
 * 	modifier
 ******************************************** */
template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool> ft::map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
	if (_tree.find(val))
		return ft::make_pair(iterator(_tree.find(val), _tree.getNil(), _tree.getRoot()), false);
	else
		return ft::make_pair(iterator(_tree.insert(val), _tree.getNil(), _tree.getRoot()), true);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	(void)position;
	return insert(val).first;
}

template <class  Key, class T, class Compare, class Alloc>
template <class InputIterator>
void ft::map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
{
	for (; first != last; ++first)
		insert(*first);
}

template<class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::erase(iterator position)
{
	//std::cout << _tree.getRoot() << std::endl;
	_tree.erase(*position);
	//std::cout << _tree.getRoot() << std::endl;
}

template<class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
	while ( first != last)
	{
		iterator tmp = first;
		++first;
		_tree.erase(*tmp);
	}
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::erase(const key_type& k)
{
	if (_tree.find(ft::make_pair(k, mapped_type())))
	{
		_tree.erase(ft::make_pair(k, mapped_type()));
		return 1;
	}
	else
		return 0;
}

template <class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::swap(map& other)
{
	Compare tmp_key = _comp;
	_comp = other._comp;
	other._comp = tmp_key;
	allocator_type tmp_alloc = _alloc;
	_alloc = other._alloc;
	other._alloc = tmp_alloc;
	_tree.swap(other._tree);
}



template <class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::clear()
{
	_tree.clear();
}

/* ********************************************
 * 	lookup
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
	if (_tree.find(ft::make_pair(k, mapped_type())))
		return 1;
	else
		return 0;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::find(const key_type& k)
{
	if (_tree.find(ft::make_pair(k, mapped_type())))
		return iterator(_tree.find(ft::make_pair(k, mapped_type())), _tree.getNil(), _tree.getRoot());
	else
		return end();
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::find(const key_type& k) const
{
if (_tree.find(ft::make_pair(k, mapped_type())))
		return iterator(_tree.find(ft::make_pair(k, mapped_type())), _tree.getNil(), _tree.getRoot());
	else
		return end();
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
	return iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())), _tree.getNil(), _tree.getRoot());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	return const_iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())), _tree.getNil(), _tree.getRoot());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	return iterator(_tree.upper_bound(ft::make_pair(k, mapped_type())), _tree.getNil(), _tree.getRoot());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	return const_iterator(_tree.upper_bound(ft::make_pair(k, mapped_type())), _tree.getNil(), _tree.getRoot());
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator> ft::map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
	return ft::make_pair(lower_bound(k), upper_bound(k));
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map<Key, T, Compare, Alloc>::const_iterator> ft::map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
	return ft::make_pair(lower_bound(k), upper_bound(k));
}

/* ********************************************
 * observer
 ******************************************** */
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::key_compare ft::map<Key, T, Compare, Alloc>::key_comp() const
{
	return _comp;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::value_compare ft::map<Key, T, Compare, Alloc>::value_comp() const
{
	return value_compare(_comp);
}


/* ********************************************
 * print
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::print(void)
{
	_tree.print_tree();
}

/* ********************************************
 * 			Non-member function overloads
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return !(rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return rhs < lhs;
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return !(lhs < rhs);
}

template <class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key, T, Compare, Alloc>& x, ft::map<Key, T, Compare, Alloc>& y)
{
	x.swap(y);
}


#endif