/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:12:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/26 19:03:36 by lle-briq         ###   ########.fr       */
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
			typedef	Node *NodeP;
			NodeP	_root;
		
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

			bool	_isLeaf(NodeP node)
			{
				return (node->left == NULL && node->right == NULL && node->color == BLACK);
			}

			NodeP	_searchNode(NodeP node, value_type value)
			{
				if (_isLeaf(node) || value == node->value)
					return (node);
				if (value < node->value)
					return (_searchNode(node->left, value));
				return (_searchNode(node->right, value));
			}

		public:
			// constructors
			RedBlackTree()
			{
				_root = new Node;
				_newLeaf(_root);
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
				while (!_isLeaf(node->left))
					node = node->left;
				return (node);
			}

			NodeP	maximum(NodeP node)
			{
				while (!_isLeaf(node->right))
					node = node->right;
				return (node);
			}

			NodeP	nextNode(NodeP node)
			{
				NodeP	cur;

				if (!_isLeaf(node->right))
					return (minimum(node->right));
				cur = node->parent;
				while (!_isLeaf(cur) && node == cur->right)
				{
					node = cur;
					cur = cur->parent;
				}
				return (cur);
			}

			NodeP	prevNode(NodeP node)
			{
				NodeP	cur;

				if (!_isLeaf(node->left))
					return (maximum(node->left));
				cur = node->parent;
				while (!_isLeaf(cur) && node == cur->left)
				{
					node = cur;
					cur = cur->parent;
				}
				return (cur);
			}
	};
}

#endif
