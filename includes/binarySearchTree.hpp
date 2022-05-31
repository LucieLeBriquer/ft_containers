/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:34:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/31 17:53:19 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP
# include "equal.hpp"
# include "pair.hpp"
# include "Node.hpp"
# include <memory>

namespace ft
{
	template < class T, class Compare >
	class binarySearchTree
	{
		private:

			typedef ft::Node<T> Node;

			Node	*_node;
			Compare	_cmp;

		public:
			binarySearchTree(const Compare &comp = Compare()) :
				_node(NULL), _cmp(comp)
			{
				return ;
			}

			~binarySearchTree()
			{
				// delete every node
			}

			Node	*research(const T& val)
			{
				return (research(val, _node, _cmp));
			}

			void	insert(const T &val)
			{
				_node = insert(val, _node, _cmp);
			}

			// static member functions
			static bool	areEqual(const Compare &comp, const T &value1, const T &value2)
			{
				return (!(comp(value1, value2) || comp(value2, value1)));
			}

			static Node	*research(const T& val, Node *node, const Compare &comp)
			{
				if (node == NULL)
					return (NULL);
				if (areEqual(comp, node->value, val))
					return (node);
				if (comp(val, node->value))
					return (research(val, node->left, comp));
				return (research(val, node->right, comp));
			}

			static Node	*insert(const T &val, Node *node, const Compare &comp)
			{

				if (node == NULL)
					return (new Node(val));
				if (areEqual(comp, val, node->value))
				{
					node->value = val;
					return (node);
				}
				if (comp(val, node->value))
				{
					node->left = insert(val, node->left, comp);
					return (node);
				}
				node->right = insert(val, node->right, comp);
				return (node);
			}
	};
}

#endif
