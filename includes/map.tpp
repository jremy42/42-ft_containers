#ifndef MAP_TPP
#define MAP_TPP

#ifndef MAP_HPP
# error "You must include map.hpp before map.tpp"
#endif

/* ********************************************
 * 	Constructors
 ******************************************** */

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) : _tree(comp)
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
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool> ft::map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
	if (_tree.find(val.first))
		return ft::pair<iterator, bool>(_tree.find(val.first), false);
	else
		return ft::pair<iterator, bool>(_tree.insert(val), true);
}
#endif