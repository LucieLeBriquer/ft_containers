/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:12:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/26 19:30:03 by lle-briq         ###   ########.fr       */
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
		
			void	_newNullNode(NodeP node, NodeP parent)
			{
				node->value = value_type();
				node->left = NULL;
				node->right = NULL;
				node->parent = parent;
				node->color = BLACK;
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
								rotateRight(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							rotateLeft(node->parent->parent);
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
								rotateLeft(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							rotateRight(node->parent->parent);
						}
					}
					if (node == _root)
						break;
				}
				_root->color = BLACK;
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
			
			NodeP	minimum(NodeP node)
			{
				while (node->left != _leaf)
					node = node->left;
				return (node);
			}

			NodeP	maximum(NodeP node)
			{
				while (node->right != _leaf)
					node = node->right;
				return (node);
			}

			NodeP	nextNode(NodeP node)
			{
				NodeP	cur;

				if (node->right != _leaf)
					return (minimum(node->right));
				cur = node->parent;
				while (cur != _leaf && node == cur->right)
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
					return (maximum(node->left));
				cur = node->parent;
				while (cur != _leaf && node == cur->left)
				{
					node = cur;
					cur = cur->parent;
				}
				return (cur);
			}

			void	rotateLeft(NodeP node)
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

			void	rotateRight(NodeP node)
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

			void	insert(value_type value)
			{
				NodeP	node = new Node<T>;
				NodeP	cur;
				NodeP	root;

				node->parent = NULL;
				node->value = value;
				node->left = _leaf;
				node->right = _leaf;
				node->color = RED;

				cur = NULL;
				root = _root;
				while (cur != _leaf)
				{
					root = cur;
					if (node->value < cur->value)
						cur = cur->left;
					else
						cur = cur->right;
				}

				node->parent = root;
				if (root == NULL)
					root = node;
				else if (node->value < root->value)
					root->left = node;
				else
					root->right = node;
				
				if (node->parent == NULL)
				{
					node->color = BLACK;
					return ;
				}
				if (node->parent->parent == NULL)
					return ;
				
				_insertionUpdate(node);
			}
	};
}

#endif
