#pragma once

#define RED 0
#define BLACK 1

namespace ft{

	template <class T>
	struct Node
	{
		public:
			typedef T value_type;
			typedef Node self;
			Node(bool color = RED) : parent(NULL), left(NULL), right(NULL) { color = _color;};
			Node(const value_type data, bool color = RED) : data(data), parent(NULL), left(NULL), right(NULL) { color = _color;};
			Node(const value_type data, Node *parent, Node *left, Node *right, const bool color = RED) : data(data), parent(parent), left(left), right(right), _color(color) {};
			Node(const Node<T> &other) : data(other.data), parent(other.parent), left(other.left), right(other.right), _color(RED) {};
			template <class U>
			Node(const Node<U> &other) : data(other.data), parent(other.parent), left(other.left), right(other.right), _color(RED) {};
			operator Node<const T>() const { return Node<const T>(data, parent, left, right, _color); };
			~Node() {};

			value_type data;
			Node *parent;
			Node *left;
			Node *right;
			int _color;
			// overload operator <
			friend bool operator<(const Node &lhs, const Node &rhs) { return lhs.data < rhs.data; };
			self& operator=(const self &other) { data = other.data; parent = other.parent; left = other.left; right = other.right; _color = other._color; return *this; };
	};
};