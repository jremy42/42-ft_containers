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
ft::map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) : _tree(comp, alloc)
{
	for (; first != last; ++first)
		_tree.insert(*first);
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const map& x) : _tree(x._tree)
{
}

/* ********************************************
 * 	Destructor
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map()
{
	_tree.clear();
}

/* ********************************************
 * 	Operators =
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>& ft::map<Key, T, Compare, Alloc>::operator=(const map& x)
{
	_tree = x._tree;
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
	iterator it = find(k);
	if (it == end())
		it = insert(ft::make_pair(k, mapped_type())).first;
	return it->second;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type& ft::map<Key, T, Compare, Alloc>::at(const key_type& k)
{
	iterator it = find(k);
	if (it == end())
		throw std::out_of_range("map::at");
	return it->second;
}

template <class Key, class T, class Compare, class Alloc>
const typename ft::map<Key, T, Compare, Alloc>::mapped_type& ft::map<Key, T, Compare, Alloc>::at(const key_type& k) const
{
	const_iterator it = find(k);
	if (it == end())
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
 * 	modifier
 ******************************************** */
template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool> ft::map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
	//std::cout << "insert called" << std::endl;
	//std::cout << "val:" << val << std::endl;
	if (_tree.find(val))
		return ft::make_pair(iterator(_tree.find(val), _tree.getNil(), _tree.getRoot()), false);
	else
		return ft::make_pair(iterator(_tree.insert(val), _tree.getNil(), _tree.getRoot()), true);
}

template <class  Key, class T, class Compare, class Alloc>
template <class InputIterator>
void ft::map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
{
	//std::cout << "insert range called" << std::endl;
	for (; first != last; ++first)
		insert(*first);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::erase(const key_type& k)
{
	return _tree.erase(ft::make_pair(k, mapped_type()));
}

template <class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::print(void)
{
	_tree.print_tree();
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
	return iterator(_tree.find(ft::make_pair(k, mapped_type())), _tree.getNil(), _tree.getRoot());
}

#endif