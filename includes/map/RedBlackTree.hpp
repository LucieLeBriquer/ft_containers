/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:12:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/08 12:05:13 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP
# include "../utils/global.hpp"
# define BLACK_C 0
# define RED_C 1

namespace ft
{

	/*
	**		NODE class
	*/

    template <typename T>
    class Node
    {
		public:
			typedef T   value_type;

			value_type	value;
			Node		*left;
			Node		*right;
			Node		*parent;
			int			color;

			Node() : value(value_type()), left(NULL), right(NULL), parent(NULL), color(BLACK_C)
			{
				return ;
			}

			Node(value_type val) : value(val), left(NULL), right(NULL), parent(NULL), color(BLACK_C)
			{
				return ;
			}

			Node(Node &node) : value(node.value), right(node.right), left(node.left), parent(node.parent), color(node.color)
			{
				return ;
			}

			Node	&operator=(const Node &node)
			{
				if (this != &node)
				{
					value = node.value;
					right = node.right;
					left = node.left;
					parent = node.parent;
					color = node.color;
				}
				return (*this);
			}

			~Node()
			{
				return ;
			}

			T	*valuePtr()
			{
				return (&value);
			}
	};
	

	/*
	**		RED-BLACK TREE
	*/

	template <typename T, class Compare>
	class RedBlackTree
	{
		private:

			//	typedef

			typedef T value_type;
			typedef	Node<T> *NodeP;


			//	member objects

			NodeP		_root;
			NodeP		_leaf;
			Compare		_comp;


			//	comparisons functions

			bool	_isLess(value_type const value1, value_type const value2) const
			{
				return (_comp(value1, value2));
			}

			bool	_isGreater(value_type const value1, const value_type value2) const
			{
				return (_comp(value2, value1));
			}


			//	create nodes

			void	_fillNewNode(NodeP node, const int color)
			{
				node->parent = NULL;
				node->left = _leaf;
				node->right = _leaf;
				node->color = color;
			}


			//	search key in tree

			NodeP	_searchNode(NodeP node, const value_type value) const
			{
				if (node == _leaf || node == NULL)
					return (NULL);
				if (areEqual(value, node->value))
					return (node);
				if (_isLess(value, node->value))
					return (_searchNode(node->left, value));
				return (_searchNode(node->right, value));
			}

			NodeP	_searchNode(NodeP node, const NodeP nodeToFind) const
			{
				if (node == _leaf || node == NULL)
					return (NULL);
				if (node == nodeToFind)
					return (node);
				if (_isLess(nodeToFind->value, node->value))
					return (_searchNode(node->left, nodeToFind));
				return (_searchNode(node->right, nodeToFind));
			}

			//	insertion and delete fix

			void	_insertionUpdate(NodeP node)
			{
				NodeP	cur;

				while (node->parent->color == RED_C)
				{
					if (node->parent == node->parent->parent->right)
					{
						cur = node->parent->parent->left;
						if (cur != NULL && cur != _leaf && cur->color == RED_C)
						{
							cur->color = BLACK_C;
							node->parent->color = BLACK_C;
							node->parent->parent->color = RED_C;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								_rotateRight(node);
							}
							node->parent->color = BLACK_C;
							node->parent->parent->color = RED_C;
							_rotateLeft(node->parent->parent);
						}
					}
					else
					{
						cur = node->parent->parent->right;
						if (cur != NULL && cur != _leaf && cur->color == RED_C)
						{
							cur->color = BLACK_C;
							node->parent->color = BLACK_C;
							node->parent->parent->color = RED_C;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								_rotateLeft(node);
							}
							node->parent->color = BLACK_C;
							node->parent->parent->color = RED_C;
							_rotateRight(node->parent->parent);
						}
					}
					if (node == _root)
						break;
				}
				_root->color = BLACK_C;
			}

			void	_deleteUpdate(NodeP node)
			{
				NodeP	cur;

				while (node != _root && node->color == BLACK_C)
				{
					if (node == node->parent->left)
					{
						cur = node->parent->right;
						if (cur->color == RED_C)
						{
							cur->color = BLACK_C;
							node->parent->color = RED_C;
							_rotateLeft(node->parent);
							cur = node->parent->right;
						}
						if (cur->left->color == BLACK_C && cur->right->color == BLACK_C)
						{
							cur->color = RED_C;
							node = node->parent;
						}
						else
						{
							if (cur->right->color == BLACK_C)
							{
								cur->left->color = BLACK_C;
								cur->color = RED_C;
								_rotateRight(cur);
								cur = node->parent->right;
							}
							cur->color = node->parent->color;
							node->parent->color = BLACK_C;
							cur->right->color = BLACK_C;
							_rotateLeft(node->parent);
							node = _root;
						}
					}
					else
					{
						cur = node->parent->left;
						if (cur->color == RED_C)
						{
							cur->color = BLACK_C;
							node->parent->color = RED_C;
							_rotateRight(node->parent);
							cur = node->parent->left;
						}
						if (cur->right->color == BLACK_C && cur->right->color == BLACK_C)
						{
							cur->color = RED_C;
							node = node->parent;
						}
						else
						{
							if (cur->left->color == BLACK_C)
							{
								cur->right->color = BLACK_C;
								cur->color = RED_C;
								_rotateLeft(cur);
								cur = node->parent->left;
							}
							cur->color = node->parent->color;
							node->parent->color = BLACK_C;
							cur->left->color = BLACK_C;
							_rotateRight(node->parent);
							node = _root;
						}
					}	
				}
				node->color = BLACK_C;
			}

			void	_replace(NodeP toRemove, NodeP newRoot)
			{
				if (toRemove->parent == NULL)
					_root = newRoot;
				else if (toRemove == toRemove->parent->left)
					toRemove->parent->left = newRoot;
				else
					toRemove->parent->right = newRoot;
				newRoot->parent = toRemove->parent;
			}


			//	rotations

			void	_rotateLeft(NodeP node)
			{
				NodeP	save = node->right;

				node->right = save->left;
				if (save->left != _leaf)
					save->left->parent = node;
				save->parent = node->parent;
				if (node->parent == NULL)
					_root = save;
				else if (node == node->parent->left)
					node->parent->left = save;
				else
					node->parent->right = save;
				save->left = node;
				node->parent = save;
			}

			void	_rotateRight(NodeP node)
			{
				NodeP	save;

				save = node->left;
				node->left = save->right;
				if (save->right != _leaf)
					save->right->parent = node;
				save->parent = node->parent;
				if (node->parent == NULL)
					_root = save;
				else if (node == node->parent->right)
					node->parent->right = save;
				else
					node->parent->left = save;
				save->right = node;
				node->parent = save;
			}


			// deletion

			void	_deleteNodesRec(NodeP node)
			{
				NodeP	nodeR;
				NodeP	nodeL;

				if (node != _leaf && node != NULL)
				{
					nodeR = node->right;
					nodeL = node->left;
					delete node;
					_deleteNodesRec(nodeR);
					_deleteNodesRec(nodeL);
				}
			}

			void	_deleteNodes(void)
			{
				_deleteNodesRec(_root);
				_root = _leaf;
			}


			//	size

			size_t	_sizeRec(NodeP node) const
			{
				if (node == _leaf || node == NULL)
					return (0);
				return (1 + _sizeRec(node->right) + _sizeRec(node->left));
			}

			
			//	deep copy

			void	_copyRec(NodeP leaf, NodeP node)
			{
				if (node != leaf)
				{
					insert(node->value);
					_copyRec(leaf, node->left);
					_copyRec(leaf, node->right);
				}
			}


		public:

			//	constructors

			RedBlackTree() : _comp(Compare())
			{
				_leaf = new Node<T>;
				_root = _leaf;
			}

			RedBlackTree(const RedBlackTree &tree)
			{
				if (this != &tree)
				{
					_leaf = new Node<T>;
					_root = _leaf;
					*this = tree;
				}
			}

			~RedBlackTree()
			{
				if (_root != _leaf && _root != NULL)
					_deleteNodes();
				delete _leaf;
			}


			// assignation

			RedBlackTree	&operator=(const RedBlackTree &tree)
			{
				if (this != &tree)
				{
					_deleteNodes();
					_copyRec(tree.getLeaf(), tree.getRoot());
				}
				return (*this);
			}



			//	min/max functions

			NodeP	minimum(NodeP node) const
			{
				if (node == NULL || node == _leaf)
					return (node);
				while (node->left != _leaf && node->left != NULL)
					node = node->left;
				return (node);
			}

			NodeP	minimum(void) const
			{
				return (minimum(_root));
			}

			NodeP	maximum(NodeP node) const
			{
				if (node == NULL || node == _leaf)
					return (node);
				while (node->right != _leaf && node->right != NULL)
					node = node->right;
				return (node);
			}

			NodeP	maximum(void) const
			{
				return (maximum(_root));
			}


			//	search in tree

			NodeP	search(const value_type value) const
			{
				return (_searchNode(_root, value));
			}

			NodeP	search(const NodeP node) const
			{
				return (_searchNode(_root, node));
			}

			//	remove in tree

			bool	remove(const value_type value)
			{
				NodeP	toDelete;
				NodeP	copy;
				NodeP	toFix;
				NodeP	node = _root;
				int		color;

				toDelete = _leaf;
				while (node != _leaf)
				{
					if (areEqual(value, node->value))
						toDelete = node;
					if (_isLess(node->value, value))
						node = node->right;
					else
						node = node->left;
				}

				// TODO didn't found key -> see how maps deals with it (exception ?)
				if (toDelete == _leaf)
					return (false);

				copy = toDelete;
				color = copy->color;
				if (toDelete->left == _leaf)
				{
					toFix = toDelete->right;
					_replace(toDelete, toDelete->right);
				}
				else if (toDelete->right == _leaf)
				{
					toFix = toDelete->left;
					_replace(toDelete, toDelete->left);
				}
				else
				{
					copy = minimum(toDelete->right);
					color = copy->color;
					toFix = copy->right;
					if (copy->parent == toDelete)
						toFix->parent = copy;
					else
					{
						_replace(copy, copy->right);
						copy->right = toDelete->right;
						copy->right->parent = copy;
					}
					_replace(toDelete, copy);
					copy->left = toDelete->left;
					copy->left->parent = copy;
					copy->color = toDelete->color;
				}
				delete toDelete;
				if (color == BLACK_C)
					_deleteUpdate(toFix);	
				return (true);
			}
			

			//	insertion
			
			NodeP	insert(const value_type value)
			{
				NodeP	node = new Node<T>(value);
				_fillNewNode(node, RED_C);


				NodeP	cur = NULL;
				NodeP	root = _root;

				while (root != _leaf)
				{
					cur = root;
					if (_isLess(node->value, cur->value))
						root = root->left;
					else
						root = root->right;
				}

				node->parent = cur;
				if (cur == NULL)
					_root = node;
				else if (_isLess(node->value, cur->value))
					cur->left = node;
				else
					cur->right = node;
				
				if (node->parent == NULL)
				{
					node->color = BLACK_C;
					return (node);
				}
				if (node->parent->parent == NULL)
				{
					return (node);
				}

				_insertionUpdate(node);
				return (node);
			}


			//	get prev and next node for tree iterator

			NodeP	nextNode(NodeP node) const
			{
				NodeP	cur;

				if (node == _leaf)
					return (minimum());

				if (node->right != _leaf && node->right != NULL)
					return (minimum(node->right));
				
				cur = node->parent;
				while (cur != _leaf && cur != NULL && node == cur->right)
				{
					node = cur;
					cur = cur->parent;
				}
				if (cur == NULL)
					cur = _leaf;
				return (cur);
			}

			NodeP	nextNode(NodeP node, size_t n) const
			{
				NodeP	res;
				
				res = node;
				for (size_t i = 0; i < n; i++)
					res = nextNode(res);
				return (res);
			}

			NodeP	prevNode(NodeP node) const
			{
				NodeP	cur;

				if (node == _leaf)
					return (maximum());

				if (node->left != _leaf && node->left != NULL)
					return (maximum(node->left));
				cur = node->parent;
				while (cur != _leaf && cur != NULL && node == cur->left)
				{
					node = cur;
					cur = cur->parent;
				}
				if (cur == NULL)
					cur = _leaf;
				return (cur);
			}

			NodeP	prevNode(NodeP node, size_t n) const
			{
				NodeP	res;
				
				res = node;
				for (size_t i = 0; i < n; i++)
					res = prevNode(res);
				return (res);
			}

			//	get root and leaf

			NodeP	getRoot(void) const
			{
				return (_root);
			}

			NodeP	getLeaf(void) const
			{
				return (_leaf);
			}

			bool	isLeaf(NodeP node) const
			{
				return (node == _leaf);
			}


			//	comparison

			bool	areEqual(const value_type value1, const value_type value2) const
			{
				return (!(_isLess(value1, value2) || _isLess(value2, value1)));
			}


			//	size

			size_t	size(void) const
			{
				return (_sizeRec(_root));
			}

			size_t	maxSize(void) const
			{
				std::allocator< Node<T> >	alloc;
				
				return (alloc.max_size());
			}


			//	clear

			void	clear(void)
			{
				_deleteNodes();
			}
	};
}

#endif
