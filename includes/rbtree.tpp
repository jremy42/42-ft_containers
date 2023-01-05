#ifndef RBTREE_TPP
#define RBTREE_TPP

#ifndef RBTREE_HPP
# error "You must include rbtree.hpp before rbtree.tpp"
#endif

#define COLOR_RED "\033[31m"
#define COLOR_BLACK "\033[30m"
#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"

// rbtree constructor
template <class T, class Compare, class Alloc, class Node>
ft::rbtree<T, Compare, Alloc, Node>::rbtree(void)
{
	_nil = NULL;
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
	printTreeWithTrunks(_root, NULL, false);
}


template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::insert(value_type data)
{
	Node *new_node = new Node(data);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	new_node->data = data;
	new_node->_color = RED;
	if (_root == NULL)
	{
		_root = new_node;
		_root->_color = BLACK;
		return;
	}
	insert_tree_preorder_mode(_root, new_node);
	if (_root->_color == RED)
		_root->_color = BLACK;

}


template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::showTrunks(Trunk *p)
{
	if (p == NULL)
		return;
  
	showTrunks(p->prev);
  
	std::cout << p->str;
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::printTreeWithTrunks(Node *root, Trunk *prev, bool is_left)
{
	if (root == NULL)
		return;
	std::string prev_str = "    ";
	Trunk *trunk = new Trunk(prev, prev_str);
	printTreeWithTrunks(root->right, trunk, true);
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
	showTrunks(trunk);
	if (root->_color == RED)
		std::cout << COLOR_RED << root->data << COLOR_RESET << std::endl;
	else
		std::cout << COLOR_BLACK << root->data << COLOR_RESET << std::endl;
	if (prev)
		prev->str = prev_str;
	trunk->str = "   |";
	printTreeWithTrunks(root->left, trunk, false);
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::insert_tree_preorder_mode(Node *root, Node *new_node)
{
	if (root == NULL)
	{
		_root = new_node;
	}
	else if (new_node->data < root->data)
	{
		if (root->left == NULL)
		{
			root->left = new_node;
			new_node->parent = root;
			if (root->_color == BLACK)
				return;
			else
				insert_fixup(new_node);
		}
		else
			insert_tree_preorder_mode(root->left, new_node);
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = new_node;
			new_node->parent = root;
			if (root->_color == BLACK)
				return;
			else
				insert_fixup(new_node);
		}
		else
			insert_tree_preorder_mode(root->right, new_node);
	}
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare,Alloc, Node>::insert_fixup(Node *new_node)
{
	Node* uncle = NULL;
	while (new_node != _root && new_node->parent->_color == RED)
	{
		if (new_node->parent == new_node->parent->parent->left)
		{
			uncle = new_node->parent->parent->right;
			if (uncle != NULL && uncle->_color == RED)
			{
				new_node->parent->_color = BLACK;
				uncle->_color = BLACK;
				new_node->parent->parent->_color = RED;
				new_node = new_node->parent->parent;
			}
			else
			{
				if (new_node == new_node->parent->right)
				{
					new_node = new_node->parent;
					rotate_left(new_node);
				}
				new_node->parent->_color = BLACK;
				new_node->parent->parent->_color = RED;
				rotate_right(new_node->parent->parent);
			}
		}
		else
		{
			uncle = new_node->parent->parent->left;
			if (uncle != NULL && uncle->_color == RED)
			{
				new_node->parent->_color = BLACK;
				uncle->_color = BLACK;
				new_node->parent->parent->_color = RED;
				new_node = new_node->parent->parent;
			}
			else
			{
				if (new_node == new_node->parent->left)
				{
					new_node = new_node->parent;
					rotate_right(new_node);
				}
				new_node->parent->_color = BLACK;
				new_node->parent->parent->_color = RED;
				rotate_left(new_node->parent->parent);
			}
		}
	}

}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::rotate_left(Node *node)
{
	// x is the node to rotate
	// y is the right child of x
	// a is the left child of x
	// b is the left child of y
	// p is the parent of x
	std::cout << "rotate left" << std::endl;
	std::cout << "node: " << node->data << std::endl;
	Node *right_child = node->right;
	node->right = right_child->left;
	if (right_child->left != NULL)
		right_child->left->parent = node;
	if (node->parent == NULL)
		_root = right_child;
	else if (node == node->parent->left)
		node->parent->left = right_child;
	else
		node->parent->right = right_child;
	right_child->parent = node->parent;
}

template <class T, class Compare, class Alloc, class Node>
void ft::rbtree<T, Compare, Alloc, Node>::rotate_right(Node *node)
{
	// x is the node to rotate
	// y is the left child of x
	// a is the right child of x
	// b is the right child of y
	// p is the parent of x
	std::cout << "rotate right" << std::endl;
	std::cout << "node: " << node->data << std::endl;
	Node *left_child = node->left;
	node->left = left_child->right;
	if (left_child->right != NULL)
		left_child->right->parent = node;
	if (node->parent == NULL)
		_root = left_child;
	else if (node == node->parent->right)
		node->parent->right = left_child;
	else
		node->parent->left = left_child;
	left_child->parent = node->parent;
}

template <class T, class Compare, class Alloc, class Node>
int	ft::rbtree<T, Compare, Alloc, Node>::get_height(Node *node)
{
	if (node == NULL)
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

#endif
