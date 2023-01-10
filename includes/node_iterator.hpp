#pragma once

#include <memory>
#include <cstddef>
#include <iterator>
#include "iterator.hpp"
#include "node.hpp"
namespace ft {

template <class T>
class node_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> 
{
	public:
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer pointer;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference reference;
		typedef ft::Node<T> node_type;
		typedef ft::Node<T>* node_pointer;
		typedef node_iterator<T> self_type;
		typedef node_iterator<T> iterator;
		typedef node_iterator<T> const_iterator;
		
	private:
		node_pointer _node;
		node_pointer _nil;
		node_pointer _root;

	public:
		node_iterator(void) : _node(NULL), _nil(NULL), _root(NULL) {};

		node_iterator(node_pointer node, node_pointer nil, node_pointer root) : _node(node), _nil(nil), _root(root) {};

		node_iterator(const node_iterator &other) : _node(other._node), _nil(other._nil), _root(other._root) {};
		~node_iterator() {};
		operator node_iterator<const T >() const { return node_iterator<const T>(_node, _nil, _root); };
		node_iterator &operator=(const node_iterator &other) { _node = other._node; _nil = other._nil; _root = other._root; return *this; };
		reference operator*(void) { return _node->data; };
		pointer operator->(void) { return &_node->data; };

		self_type &operator++(void) {
			if (_node == _nil)
				_node = _min(_root);
			else
			{
				if (_node->right != _nil) {
					_node = _node->right;
					while (_node->left != _nil)
						_node = _node->left;
				}
				else {
					node_pointer parent = _node->parent;
					while (_node == parent->right) {
						_node = parent;
						parent = parent->parent;
					}
					if (_node->right != parent)
						_node = parent;
				}
			}
			return *this;
		};

		self_type operator++(int) {
			self_type tmp(*this);
			operator++();
			return tmp;
		};

		self_type &operator--(void) {
			if (_node == _nil)
				_node = _max(_root);
			else
			{
				if (_node->_color == RED && _node->parent->parent == _node)
					_node = _node->right;
				else if (_node->left != _nil) {
					node_pointer tmp = _node->left;
					while (tmp->right != _nil)
						tmp = tmp->right;
					_node = tmp;
				}
				else {
					node_pointer parent = _node->parent;
					while (_node == parent->left) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
			}
			return *this;
		};

		self_type operator--(int) {
			self_type tmp(*this);
			operator--();
			return tmp;
		}
		friend bool operator==(const self_type &lhs, const self_type &rhs) { return lhs._node == rhs._node; };
		friend bool operator!=(const self_type &lhs, const self_type &rhs) { return lhs._node != rhs._node; };

		private:
			node_pointer _max(node_pointer _root)
			{
				while (_root->right != _nil)
					_root = _root->right;
				return _root;
			}

			node_pointer _min(node_pointer _root)
			{
				while (_root->left != _nil)
					_root = _root->left;
				return _root;
			}
	};

		
};
