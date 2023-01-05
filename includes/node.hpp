#pragma once

#define RED 0
#define BLACK 1

namespace ft{

	template <class T>
	struct Node
	{
		typedef T value_type;
		Node(bool color = RED) : parent(NULL), left(NULL), right(NULL) { color = _color;};
		Node(value_type data, bool color = RED) : data(data), parent(NULL), left(NULL), right(NULL) { color = _color;};
		Node(value_type data, Node *parent, Node *left, Node *right, bool color = RED) : data(data), parent(parent), left(left), right(right) { color = _color; };
	
		~Node() {};

		value_type data;
		Node *parent;
		Node *left;
		Node *right;
		int _color;
	};
}