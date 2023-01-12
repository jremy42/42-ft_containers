
#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "node.hpp"
#include "pair.hpp"
#include <memory>
#include "binary_predicate.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "node_iterator.hpp"

struct Trunk
{
    Trunk *prev;
    std::string str;
 
    Trunk(Trunk *prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

namespace ft
{
	template <class T, class Compare, class Alloc = std::allocator<ft::Node<T> >, class Node = ft::Node<T> >
	class rbtree
	{
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;
		typedef Compare key_compare;
		typedef ft::node_iterator<value_type> iterator;

		public: 
			rbtree(void);
			rbtree(const key_compare &comp = key_compare());
			//rbtree(const rbtree &other);
			~rbtree();	
			//rbtree &operator=(const rbtree &other);
			
			//lookup
			void print_tree(void);
			int size(void) const;
			pointer find(const value_type data) const;
			bool is_valid_tree(void); // deprecated
			bool check_black_balanced(pointer node);
			bool empty(void) const;
			size_type max_size(void) const;


			// modifier
			void clear(void);
			pointer insert(const value_type data);
			bool erase(const value_type data);
			void swap(rbtree &other);

			// get
			pointer getRoot(void) const;
			pointer getNil(void) const;
			pointer getMin(void) const;
			pointer getMax(void) const;

			//lookup
			pointer lower_bound(const value_type data) const;
			pointer upper_bound(const value_type data) const;

		private:
			pointer _root;
			pointer _nil;
			allocator_type _alloc;
			key_compare _comp;
			//size_type _size;

			// insert functions
			void _insert_tree_preorder_mode(pointer root, pointer node);
			void _rotate_left(pointer node);
			void _rotate_right(pointer node);
			void _insert_fixup(pointer node);
			void _delete_fixup(pointer node);
			int _get_height(pointer node);
			void _transplant(pointer node1, pointer node2);
			// print functions
			void _showTrunks(Trunk *p);
			void _printTreeWithTrunks(pointer root, Trunk *prev, bool isLeft);
			void _clear(pointer node);
			pointer _find(pointer node, const value_type data) const;
			void	_erase(pointer node);
			pointer _findMin(pointer node) const;
			pointer _findMax(pointer node) const;
			bool	_is_valid_tree(pointer node);
			bool	_is_equilibrated(pointer node);
			int		_depthMin(pointer node, int depth);
			int		_depthMax(pointer node, int depth);
			int 	_depthBlack(pointer node);
			int		_getSize(pointer node) const;
			pointer _lower_bound(pointer node, const value_type data) const;
			pointer _upper_bound(pointer node, const value_type data) const;
	};


#define COLOR_RED "\033[31m"
#define COLOR_BLACK "\033[33m"
#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"

// rbtree constructor
template <class T, class Compare, class Alloc, class Node>
ft::rbtree<T, Compare, Alloc, Node>::rbtree(void)
{
	value_type value;
	_alloc = allocator_type();
	_nil = _alloc.allocate(1);
	_alloc.construct(_nil, Node(value, BLACK));
	_nil->_color = BLACK;
	_nil->left = NULL;
	_nil->right = NULL;
	_nil->parent = NULL;
	_nil->data = 0;
	_root = _nil;
}

template <class T, class Compare, class Alloc, class Node>
ft::rbtree<T, Compare, Alloc, Node>::rbtree(const key_compare &comp) : _comp(comp)
{
	value_type value;
	_nil = _alloc.allocate(1);
	_alloc.construct(_nil, Node(value, BLACK));
	_nil->_color = BLACK;
	_nil->left = NULL;
	_nil->right = NULL;
	_nil->parent = NULL;
	_root = _nil;
}

template <class T, class Compare, class Alloc, class Node>
ft::rbtree<T, Compare, Alloc, Node>::~rbtree()
{
	if (_root != NULL)
	{
		if (_root != _nil)
			_clear(_root);
		_alloc.deallocate(_nil, 1);
		_root = NULL;
	}
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::print_tree(void)
{
	_printTreeWithTrunks(_root, NULL, false);
}

template <class T, class Compare, class Alloc, class Node>
int ft::rbtree<T, Compare, Alloc, Node>::size(void) const
{
	return _getSize(_root);
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::find(const value_type data) const
{
	return (_find(_root, data));
}

template <class T, class Compare, class Alloc, class Node>
bool ft::rbtree<T, Compare, Alloc, Node>::is_valid_tree(void)
{
	return (_is_valid_tree(_root) && _is_equilibrated(_root));
}

template <class T, class Compare, class Alloc, class Node>
bool ft::rbtree<T, Compare, Alloc, Node>::check_black_balanced(pointer node)
{
	if (node == _nil)
		return true;
	int black_depth_left = _depthBlack(node->left);
	int black_depth_right = _depthBlack(node->right);
	if (black_depth_left != black_depth_right)
		return false;
	return (check_black_balanced(node->left) && check_black_balanced(node->right));
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::clear(void)
{
	_clear(_root);
	_root = _nil;
}

template <class T, class Compare, class Alloc, class Node>
bool ft::rbtree<T, Compare, Alloc, Node>::empty(void) const
{
	return (_root == _nil);
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::size_type ft::rbtree<T, Compare, Alloc, Node>::max_size(void) const
{
	return (_alloc.max_size());
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::insert(const value_type data)
{
	pointer new_node;

	if (find(data) != NULL)
		return find(data);
	try
	{
		new_node = _alloc.allocate(1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	_alloc.construct(new_node, Node(data));
	new_node->left = _nil;
	new_node->right = _nil;
	new_node->_color = RED;
	new_node->parent = _nil;
	if (_root == _nil)
	{
		_root = new_node;
		_root->_color = BLACK;
		_root->parent = _nil;
		return (new_node);
	}
	_insert_tree_preorder_mode(_root, new_node);
	if (_root->_color == RED)
		_root->_color = BLACK;
	return (new_node);
}

template <class T, class Compare, class Alloc, class Node>
bool ft::rbtree<T, Compare, Alloc, Node>::erase(const value_type data)
{
	pointer node = _find(_root, data);
	if (node == _nil)
		return (false);
	_erase(node);
	return (true);
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::swap(rbtree &other)
{
	pointer tmp_root = _root;
	pointer tmp_nil = _nil;
	key_compare tmp_comp = _comp;
	allocator_type tmp_alloc = _alloc;
	_root = other._root;
	_nil = other._nil;
	_comp = other._comp;
	_alloc = other._alloc;
	other._root = tmp_root;
	other._nil = tmp_nil;
	other._comp = tmp_comp;
	other._alloc = tmp_alloc;
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::getRoot(void) const
{
	return _root;
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::getNil(void) const
{
	return _nil;
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::getMin(void) const
{
	return _findMin(_root);
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::getMax(void) const
{
	return _findMax(_root);
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::lower_bound(const value_type data) const
{
	return _lower_bound(_root, data);
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::upper_bound(const value_type data) const
{
	return _upper_bound(_root, data);
}

/*private function*/

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_insert_tree_preorder_mode(pointer root, pointer new_node)
{
	if (root == _nil)
	{
		_root = new_node;
	}
	else if (_comp(new_node->data, root->data))
	{
		if (root->left == _nil)
		{
			root->left = new_node;
			new_node->parent = root;
			if (root->_color == BLACK)
				return;
			else
				_insert_fixup(new_node);
		}
		else
			_insert_tree_preorder_mode(root->left, new_node);
	}
	else
	{
		if (root->right == _nil)
		{
			root->right = new_node;
			new_node->parent = root;
			if (root->_color == BLACK)
				return;
			else
				_insert_fixup(new_node);
		}
		else
			_insert_tree_preorder_mode(root->right, new_node);
	}
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_erase(pointer node)
{
	// successor == y
	int original_color = node->_color;
	pointer node_to_del = node;
	pointer node_to_fix = _nil;
	if (node->left == _nil)
	{
		node_to_fix = node->right;
		_transplant(node, node->right);
	}
	else if (node->right == _nil)
	{
		node_to_fix = node->left;
		_transplant(node, node->left);
	}
	else
	{
		// successor == y
		// successor_right == x
		pointer successor = _findMin(node->right);
		original_color = successor->_color;
		pointer successor_right = successor->right;
		node_to_fix = successor_right;
		if (successor->parent == node)
		{
			successor_right->parent = successor;
		}
		else
		{
			_transplant(successor, successor_right);
			successor->right = node->right;
			successor->right->parent = successor;
		}
		_transplant(node, successor);
		successor->left = node->left;
		successor->left->parent = successor;
		successor->_color = node->_color;
	}
	_alloc.destroy(node_to_del);
	_alloc.deallocate(node_to_del, 1);
	if (original_color == BLACK)
		_delete_fixup(node_to_fix);
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_rotate_left(pointer node)
{
	// x is the node to rotate
	// y is the right child of x
	// a is the left child of x
	// b is the left child of y
	// p is the parent of x
	// std::cout << "rotate left" << std::endl;
	// std::cout << "node" << node->data << std::endl;
	pointer right_child = node->right;
	node->right = right_child->left;
	if (right_child->left != _nil)
		right_child->left->parent = node;
	right_child->parent = node->parent;
	if (node->parent == _nil)
		_root = right_child;
	else if (node == node->parent->left)
		node->parent->left = right_child;
	else
		node->parent->right = right_child;
	right_child->left = node;
	node->parent = right_child;
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_rotate_right(pointer node)
{
	// x is the node to rotate
	// y is the left child of x
	// a is the right child of x
	// b is the right child of y
	// p is the parent of x
	// std::cout << "rotate right" << std::endl;
	// std::cout << "node" << node->data << std::endl;
	pointer left_child = node->left;
	node->left = left_child->right;
	if (left_child->right != _nil)
		left_child->right->parent = node;
	left_child->parent = node->parent;
	if (node->parent == _nil)
		_root = left_child;
	else if (node == node->parent->right)
		node->parent->right = left_child;
	else
		node->parent->left = left_child;
	left_child->right = node;
	node->parent = left_child;
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_insert_fixup(pointer new_node)
{
	pointer uncle;
	while (new_node != _root && new_node->parent->_color == RED)
	{
		if (new_node->parent == new_node->parent->parent->left)
		{
			uncle = new_node->parent->parent->right;
			if (uncle != _nil && uncle->_color == RED)
			{
				new_node->parent->_color = BLACK;
				uncle->_color = BLACK;
				if (new_node->parent->parent != _nil && new_node->parent->parent != _root)
					new_node->parent->parent->_color = RED;
				new_node = new_node->parent->parent;
			}
			else
			{
				if (new_node == new_node->parent->right)
				{
					new_node = new_node->parent;
					_rotate_left(new_node);
				}
				new_node->parent->_color = BLACK;
				new_node->parent->parent->_color = RED;
				_rotate_right(new_node->parent->parent);
			}
		}
		else
		{
			uncle = new_node->parent->parent->left;
			if (uncle != _nil && uncle->_color == RED)
			{
				new_node->parent->_color = BLACK;
				uncle->_color = BLACK;
				if (new_node->parent->parent != _nil && new_node->parent->parent != _root)
					new_node->parent->parent->_color = RED;
				new_node = new_node->parent->parent;
			}
			else
			{
				if (new_node == new_node->parent->left)
				{
					new_node = new_node->parent;
					_rotate_right(new_node);
				}
				new_node->parent->_color = BLACK;
				new_node->parent->parent->_color = RED;
				_rotate_left(new_node->parent->parent);
			}
		}
	}
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_delete_fixup(pointer node)
{
	// node == x
	// sibling == w
	//	std::cout << "delete fixup" << std::endl;
	// std::cout << "node: " << node->data << std::endl;
	pointer sibling = NULL;
	// std::cout << "print node: " << std::endl;
	//_printTreeWithTrunks(node, NULL, false);
	// std::cout << "node parent: " << node->parent->data << std::endl;
	if (node == _nil && node->parent == _nil)
		return;
	while (node != _root && node->_color == BLACK)
	{
		if (node == node->parent->left)
		{
			sibling = node->parent->right;
			// std::cout << "sibling " << sibling->data << std::endl;
			if (sibling && sibling->_color == RED)
			{
				sibling->_color = BLACK;
				node->parent->_color = RED;
				_rotate_left(node->parent);
				sibling = node->parent->right;
			}
			if ((sibling->left && sibling->left->_color == BLACK) && (sibling->right && sibling->right->_color == BLACK))
			{
				sibling->_color = RED;
				node = node->parent;
			}
			else
			{
				if (sibling && sibling->right->_color == BLACK)
				{
					sibling->left->_color = BLACK;
					sibling->_color = RED;
					_rotate_right(sibling);
					sibling = node->parent->right;
				}
				if (sibling)
					sibling->_color = node->parent->_color;
				node->parent->_color = BLACK;
				if (sibling && sibling->right)
					sibling->right->_color = BLACK;
				_rotate_left(node->parent);
				node = _root;
			}
		}
		else
		{
			sibling = node->parent->left;
			if (sibling && sibling->_color == RED)
			{
				sibling->_color = BLACK;
				node->parent->_color = RED;
				_rotate_right(node->parent);
				sibling = node->parent->left;
			}
			if (sibling && sibling->right->_color == BLACK && sibling->left->_color == BLACK)
			{
				sibling->_color = RED;
				node = node->parent;
			}
			else
			{
				if (sibling && sibling->left->_color == BLACK)
				{
					sibling->right->_color = BLACK;
					sibling->_color = RED;
					_rotate_left(sibling);
					sibling = node->parent->left;
				}
				if (sibling)
					sibling->_color = node->parent->_color;
				node->parent->_color = BLACK;
				if (sibling && sibling->left)
					sibling->left->_color = BLACK;
				_rotate_right(node->parent);
				node = _root;
			}
		}
	}
	if (node)
		node->_color = BLACK;
}

template <class T, class Compare, class Alloc, class Node>
int ft::rbtree<T, Compare, Alloc, Node>::_get_height(pointer node)
{
	if (node == _nil)
		return 0;
	else
	{
		int left_height = get_height(node->left);
		int right_height = get_height(node->right);

		if (left_height > right_height)
			return (left_height + 1);
		else
			return (right_height + 1);
	}
}
template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_transplant(pointer node, pointer child)
{
	// std::cout << "transplant" << std::endl;
	// std::cout << "node " << node->data << std::endl;
	// std::cout << "child " << child->data << std::endl;
	if (node->parent == _nil)
		_root = child;
	else if (node == node->parent->left)
		node->parent->left = child;
	else
		node->parent->right = child;
	// std::cout << "node->parent " << node->parent->data << std::endl;
	child->parent = node->parent;
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::_find(pointer root, const value_type data) const
{
	if (root == _nil)
		return (NULL);
	if (root->data.first == data.first)
		return (root);
	if (data < root->data)
		return (_find(root->left, data));
	else
		return (_find(root->right, data));
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::_findMin(pointer root) const
{
	if (!root || root == _nil)
		return (_nil);
	if (root->left == _nil)
		return (root);
	return (_findMin(root->left));
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::_findMax(pointer root) const
{
	if (!root || root == _nil)
		return (_nil);
	if (root->right == _nil)
		return (root);
	return (_findMax(root->right));
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_showTrunks(Trunk *p)
{
	if (p == NULL)
		return;

	_showTrunks(p->prev);

	std::cout << p->str;
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_printTreeWithTrunks(pointer root, Trunk *prev, bool is_left)
{
	if (root == NULL)
		return;
	std::string prev_str = "    ";
	Trunk *trunk = new Trunk(prev, prev_str);
	_printTreeWithTrunks(root->right, trunk, true);
	if (!prev)
		trunk->str = "---";
	else if (is_left)
	{
		trunk->str = ".---";
		prev_str = "   |";
	}
	else
	{
		trunk->str = "`---";
		prev->str = prev_str;
	}
	_showTrunks(trunk);
	if (root->_color == RED)
		std::cout << COLOR_RED << root->data << COLOR_RESET << std::endl;
	else
		std::cout << COLOR_BLACK << root->data << COLOR_RESET << std::endl;
	if (prev)
		prev->str = prev_str;
	trunk->str = "   |";
	_printTreeWithTrunks(root->left, trunk, false);
}

template <class T, class Compare, class Alloc, class Node>
bool ft::rbtree<T, Compare, Alloc, Node>::_is_equilibrated(pointer root)
{
	if (root == _nil)
		return true;
	int left_depth = _depthMin(root->left, 0);
	int right_depth = _depthMax(root->right, 0);
	if (left_depth - right_depth > 1 || right_depth - left_depth > 1)
		return false;
	return (_is_equilibrated(root->left) && _is_equilibrated(root->right));
}

template <class T, class Compare, class Alloc, class Node>
int ft::rbtree<T, Compare, Alloc, Node>::_depthMin(pointer root, int depth)
{
	if (root == _nil)
		return depth;
	return _depthMin(root->left, depth + 1);
}

template <class T, class Compare, class Alloc, class Node>
int ft::rbtree<T, Compare, Alloc, Node>::_depthMax(pointer root, int depth)
{
	if (root == _nil)
		return depth;
	return _depthMax(root->right, depth + 1);
}

template <class T, class Compare, class Alloc, class Node>
int ft::rbtree<T, Compare, Alloc, Node>::_depthBlack(pointer root)
{
	if (root == _nil)
		return 1;
	if (root->_color == BLACK)
		return (1 + _depthBlack(root->left));
	else
		return (_depthBlack(root->left));
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_clear(pointer node)
{
	if (node == _nil)
		return;
	_clear(node->left);
	_clear(node->right);
	_alloc.destroy(node);
	_alloc.deallocate(node, 1);
}

template <class T, class Compare, class Alloc, class Node>
int ft::rbtree<T, Compare, Alloc, Node>::_getSize(pointer node) const
{
	if (node == _nil)
		return 0;
	return _getSize(node->left) + _getSize(node->right) + 1;
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::_lower_bound(pointer node, const value_type data) const
{
	if (node == _nil)
		return (_nil);
	if (!_comp(data, node->data) && _comp(node->data, data))
		return (_lower_bound(node->right, data));
	else
	{
		pointer tmp = _lower_bound(node->left, data);
		if (tmp == _nil)
			return (node);
		else
			return (tmp);
	}
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::_upper_bound(pointer node, const value_type data) const
{
	if (node == _nil)
		return (_nil);
	if (!_comp(data, node->data))
		return (_upper_bound(node->right, data));
	else
	{
		pointer tmp = _upper_bound(node->left, data);
		if (tmp == _nil)
			return (node);
		else
			return (tmp);
	}
}

template <class T, class Compare, class Alloc, class Node>
bool ft::rbtree<T, Compare, Alloc, Node>::_is_valid_tree(pointer root)
{
	if (root == _nil)
		return true;
	if (root->_color == RED)
	{
		if (root->left->_color == RED || root->right->_color == RED)
			return false;
	}
	return (_is_valid_tree(root->left) && _is_valid_tree(root->right));
}

//#include "rbtree.tpp"
};
#endif
