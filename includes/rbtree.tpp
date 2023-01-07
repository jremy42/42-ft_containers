#ifndef RBTREE_TPP
#define RBTREE_TPP

#ifndef RBTREE_HPP
# error "You must include rbtree.hpp before rbtree.tpp"
#endif
#include <iostream>

#define COLOR_RED "\033[31m"
#define COLOR_BLACK "\033[33m"
#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"

// rbtree constructor
template <class T, class Compare, class Alloc, class Node>
ft::rbtree<T, Compare, Alloc, Node>::rbtree(void)
{

	_nil = _alloc.allocate(1);
	_alloc.construct(_nil, value_type());
	_nil->_color = BLACK;
	_nil->left = NULL;
	_nil->right = NULL;
	_nil->parent = NULL;
	_root = _nil;
}
template <class T, class Compare, class Alloc, class Node>
ft::rbtree<T, Compare, Alloc, Node>::rbtree(const rbtree &other)
{
	*this = other;
}

template <class T, class Compare, class Alloc, class Node>
ft::rbtree<T, Compare, Alloc, Node>::~rbtree()
{
}

template <class T, class Compare, class Alloc, class Node>
ft::rbtree<T, Compare, Alloc, Node> &ft::rbtree<T, Compare, Alloc, Node>::operator=(const rbtree &other)
{
	if (this != &other)
	{
		_root = other._root;
	}
	return *this;
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::print_tree(void)
{
	_printTreeWithTrunks(_root, NULL, false);
}


template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::insert(value_type data)
{
	pointer new_node;

	try
	{
		new_node = _alloc.allocate(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	_alloc.construct(new_node, value_type(data));
	new_node->left = _nil;
	new_node->right = _nil;
	new_node->_color = RED;
	new_node->parent = NULL;
	std::cout << "inserting " << new_node->data << std::endl;
	std::cout << "new_node->color = " << new_node->_color << std::endl;
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
void ft::rbtree<T, Compare, Alloc, Node>::_insert_tree_preorder_mode(pointer root, pointer new_node)
{
	if (root == _nil)
	{
		_root = new_node;
	}
	else if (new_node->data < root->data)
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
void ft::rbtree<T, Compare,Alloc, Node>::_insert_fixup(pointer new_node)
{
	pointer  uncle;
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
				if (new_node->parent->parent != _nil && new_node->parent->parent != _root)
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
				if (new_node->parent->parent != _nil && new_node->parent->parent != _root)
					new_node->parent->parent->_color = RED;
				_rotate_left(new_node->parent->parent);
			}
		}
	}

}

template <class T, class Compare, class Alloc, class Node>
bool ft::rbtree<T, Compare, Alloc, Node>::erase(value_type data)
{
	pointer node = _find(_root, data);
	if (node == _nil)
		return (false);
	_erase(node);
	return (true);
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_erase(pointer node)
{
	std::cout << "erase " << node->data << std::endl;
	// successor == y
	int original_color = node->_color;
	pointer node_to_del = node;
	pointer node_to_fix = _nil;
	if (node->left == _nil)
	{
		std::cout << "left == NULL" << std::endl;
		node_to_fix = node->right;
		std::cout << "node_to_fix " << node_to_fix << std::endl;
		_transplant(node, node->right);
	}
	else if (node->right == _nil)
	{
		std::cout << "right == NULL" << std::endl;
		node_to_fix = node->left;
		_transplant(node, node->left);
	}
	else
	{
		// successor == y
		// successor_right == x
		std::cout << "left != NULL && right != NULL" << std::endl;
		pointer successor = _findMin(node->right);
		original_color = successor->_color;
		pointer successor_right = successor->right;
		if (successor->parent == node)
		{
			std::cout << "successor->parent == node" << std::endl;
			if (successor_right != _nil)
			{
				successor_right->parent = successor;
				node_to_fix = successor_right;
			}
		}
		else
		{
			std::cout << "successor->parent != node" << std::endl;
			_transplant(successor, successor_right);
			successor->right = node->right;
			successor->right->parent = successor;
		}
		_transplant(node, successor);
		successor->left = node->left;
		successor->left->parent = successor;
		successor->_color = node->_color;
		node_to_fix = successor_right;
	}
	_alloc.destroy(node_to_del);
	_alloc.deallocate(node_to_del, 1);
	if (original_color == BLACK)
		_delete_fixup(node_to_fix);
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_delete_fixup(pointer node)
{
	// node == x
	//sibling == w
	std::cout << "delete fixup" << std::endl;
	std::cout << "node: " << node->data << std::endl;
	print_tree();
	pointer sibling = NULL;
	while (node != _root && node->_color == BLACK)
	{
		if (node == node->parent->left)
		{
			sibling = node->parent->right;
			if (sibling->_color == RED)
			{
				sibling->_color = BLACK;
				node->parent->_color = RED;
				_rotate_left(node->parent);
				sibling = node->parent->right;
			}
			if (sibling->left->_color == BLACK && sibling->right->_color == BLACK)
			{
				sibling->_color = RED;
				node = node->parent;
			}
			else
			{
				if (sibling->right->_color == BLACK)
				{
					sibling->left->_color = BLACK;
					sibling->_color = RED;
					_rotate_right(sibling);
					sibling = node->parent->right;
				}
				sibling->_color = node->parent->_color;
				node->parent->_color =BLACK;
				sibling->right->_color = BLACK;
				_rotate_left(node->parent);
				node = _root;
			}
		}
		else 
		{
			sibling = node->parent->left;
			if (sibling->_color == RED)
			{
				sibling->_color = BLACK;
				node->parent->_color = RED;
				_rotate_right(node->parent);
				sibling = node->parent->left;
			}
			if (sibling->right->_color == BLACK && sibling->left->_color == BLACK)
			{
				sibling->_color = RED;
				node = node->parent;
			}
			else
			{
				if (sibling->left->_color == BLACK)
				{
					sibling->right->_color = BLACK;
					sibling->_color = RED;
					_rotate_left(sibling);
					sibling = node->parent->left;
				}
				sibling->_color = node->parent->_color;
				node->parent->_color = BLACK;
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
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::find(value_type data)
{
	return (_find(_root, data));
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::_find(pointer root, value_type data)
{
	if (root == _nil)
		return (_nil);
	if (root->data == data)
		return (root);
	if (data < root->data)
		return (_find(root->left, data));
	else
		return (_find(root->right, data));
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::_findMin(pointer root)
{
	if (root == _nil)
		return (_nil);
	if (root->left == _nil)
		return (root);
	return (_findMin(root->left));
}

template <class T, class Compare, class Alloc, class Node>
typename ft::rbtree<T, Compare, Alloc, Node>::pointer ft::rbtree<T, Compare, Alloc, Node>::_findMax(pointer root)
{
	if (root == _nil)
		return (_nil);
	if (root->right == _nil)
		return (root);
	return (_findMax(root->right));
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_transplant(pointer node, pointer child)
{
	if (node->parent == _nil)
		_root = child;
	else if (node == node->parent->left)
		node->parent->left = child;
	else
		node->parent->right = child;
	child->parent = node->parent;
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::_rotate_left(pointer node)
{
	// x is the node to rotate
	// y is the right child of x
	// a is the left child of x
	// b is the left child of y
	// p is the parent of x
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
int	ft::rbtree<T, Compare, Alloc, Node>::_get_height(pointer node)
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

#endif
