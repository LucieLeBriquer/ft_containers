/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:12:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/27 12:50:28 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP
# include "equal.hpp"
# define BLACK 0
# define RED 1

namespace ft 
{
    template <typename T>
    struct Node
    {
		typedef T   value_type;

		value_type	value;
		Node		*left;
		Node		*right;
		Node		*parent;
		int			color;
	};
	
	template <typename T>
	class RedBlackTree
	{
		private:
			typedef T value_type;
			typedef	Node<T> *NodeP;
			NodeP	_root;
			NodeP	_leaf;

			void	_fillNewNode(NodeP node, value_type value, int color)
			{
				node->parent = NULL;
				node->value = value;
				node->left = _leaf;
				node->right = _leaf;
				node->color = color;
			}

			void	_newLeaf(NodeP node)
			{
				node->left = NULL;
				node->right = NULL;
				node->color = BLACK;
			}

			NodeP	_searchNode(NodeP node, value_type value)
			{
				if (node == _leaf || value == node->value)
					return (node);
				if (value < node->value)
					return (_searchNode(node->left, value));
				return (_searchNode(node->right, value));
			}

			void	_insertionUpdate(NodeP node)
			{
				NodeP	cur;

				while (node->parent->color == RED)
				{
					if (node->parent == node->parent->parent->right)
					{
						cur = node->parent->parent->left;
						if (cur->color == RED)
						{
							cur->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								_rotateRight(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							_rotateLeft(node->parent->parent);
						}
					}
					else
					{
						cur = node->parent->parent->right;
						if (cur->color == RED)
						{
							cur->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								_rotateLeft(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							_rotateRight(node->parent->parent);
						}
					}
					if (node == _root)
						break;
				}
				_root->color = BLACK;
			}

			void	_deleteUpdate(NodeP node)
			{
				NodeP	cur;

				while (node != _root && node->color == BLACK)
				{
					if (node == node->parent->left)
					{
						cur = node->parent->right;
						if (cur->color == RED)
						{
							cur->color = BLACK;
							node->parent->color = RED;
							_rotateLeft(node->parent);
							cur = node->parent->right;
						}
						if (cur->left->color == BLACK && cur->right->color == BLACK)
						{
							cur->color = RED;
							cur = cur->parent;
						}
						else
						{
							if (cur->right->color == BLACK)
							{
								cur->left->color = BLACK;
								cur->color = RED;
								_rotateRight(cur);
								cur = cur->parent->right;
							}
							cur->color = node->parent->color;
							node->parent->color = BLACK;
							cur->right->color = BLACK;
							_rotateLeft(node->parent);
							node = _root;
						}
					}
					else
					{
						cur = node->parent->left;
						if (cur->color == RED)
						{
							cur->color = BLACK;
							node->parent->color = RED;
							_rotateRight(node->parent);
							cur = node->parent->left;
						}
						if (cur->right->color == BLACK && cur->right->color == BLACK)
						{
							cur->color = RED;
							node = node->parent;
						}
						else
						{
							if (cur->left->color == BLACK)
							{
								cur->right->color = BLACK;
								cur->color = RED;
								_rotateLeft(cur);
								cur = node->parent->left;
							}
							cur->color = node->parent->color;
							node->parent->color = BLACK;
							cur->left->color = BLACK;
							_rotateRight(node->parent);
							node = _root;
						}
					}	
				}
				node->color = BLACK;
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

			NodeP	_minimum(NodeP node)
			{
				while (node->left != _leaf)
					node = node->left;
				return (node);
			}

			NodeP	_maximum(NodeP node)
			{
				while (node->right != _leaf)
					node = node->right;
				return (node);
			}
			
			void	_rotateLeft(NodeP node)
			{
				NodeP	save;

				save = node->right;
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

			// to delete
			void	_printTreeRec(NodeP root, std::string indent, bool last)
			{
				if (root != _leaf)
				{
					std::cout << indent;
					if (last)
					{
						std::cout << "R----";
						indent += "   ";
					}
					else
					{
						std::cout << "L----";
						indent += "|  ";
					}

					std::string sColor = root->color ? "RED" : "BLACK";
					std::cout << root->value << "(" << sColor << ")" << std::endl;
					_printTreeRec(root->left, indent, false);
					_printTreeRec(root->right, indent, true);
				}
			}

		public:
			// constructors
			RedBlackTree()
			{
				_leaf = new Node<T>;
				_newLeaf(_leaf);
				_root = _leaf;
			}

			~RedBlackTree()
			{
				// free everything;
			}

			NodeP	search(value_type value)
			{
				return (_searchNode(_root, value));
			}

			void	remove(value_type value)
			{
				NodeP	toDelete;
				NodeP	copy;
				NodeP	toFix;
				NodeP	node = _root;
				int		color;

				toDelete = _leaf;
				while (node != _leaf)
				{
					if (node->value == value)
					{
						toDelete = node;
						break;
					}
					if (node->value <= value)
						node = node->right;
					else
						node = node->left;
				}

				// didn't found key -> see how maps deals with it
				if (toDelete == _leaf)
					return ;

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
					copy = _minimum(toDelete->right);
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
				if (color == BLACK)
					_deleteUpdate(toFix);
				
			}

			void	insert(value_type value)
			{
				NodeP	node = new Node<T>;
				NodeP	cur;
				NodeP	root;

				_fillNewNode(node, value, RED);

				cur = NULL;
				root = _root;
				while (root != _leaf)
				{
					cur = root;
					if (node->value < cur->value)
						root = root->left;
					else
						root = root->right;
				}

				node->parent = cur;
				if (cur == NULL)
					_root = node;
				else if (node->value < cur->value)
					cur->left = node;
				else
					cur->right = node;
				
				if (node->parent == NULL)
				{
					node->color = BLACK;
					return ;
				}
				if (node->parent->parent == NULL)
				{
					return ;
				}
				_insertionUpdate(node);
			}

			// to delete
			void	printTree(void)
			{
				_printTreeRec(_root, "", true);
				std::cout << std::endl;
			}

			// for tree iterator
			NodeP	nextNode(NodeP node)
			{
				NodeP	cur;

				if (node->right != _leaf)
					return (_minimum(node->right));
				cur = node->parent;
				while (cur != _leaf && cur != NULL && node == cur->right)
				{
					node = cur;
					cur = cur->parent;
				}
				return (cur);
			}

			NodeP	prevNode(NodeP node)
			{
				NodeP	cur;

				if (node->left != _leaf)
					return (_maximum(node->left));
				cur = node->parent;
				while (cur != _leaf && cur != NULL && node == cur->left)
				{
					node = cur;
					cur = cur->parent;
				}
				return (cur);
			}

			void	_test(NodeP node)
			{
				NodeP	cur = node;

				while (cur != _leaf && cur != NULL)
				{
					std::cout << cur->value << std::endl;
					cur = nextNode(cur);
				}
			}
			
			void	test(void)
			{
				_test(_minimum(_root));
			}

	};
}

#endif
