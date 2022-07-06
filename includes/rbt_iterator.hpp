/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:50:32 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/06 17:24:23 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP
# include "RedBlackTree.hpp"
# include "iterators_traits.hpp"

namespace ft
{
	template <typename T, class Compare>
	class RedBlackIterator
    {
		protected:
		
			//	typedefs

			typedef RedBlackTree<T, Compare> Tree;
			typedef Node<T> *NodeP;


			//	member objects

			Tree	_tree;
			NodeP	_node;


		public:

			//	typedefs

			typedef T								value_type;
			typedef T&								reference;
			typedef T*   							pointer;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;


			//	constructors

			RedBlackIterator() : _tree(Tree()), _node(_tree.getRoot()) { }
			RedBlackIterator(const Tree& tree) : _tree(tree), _node(_tree.getRoot()) { }
			RedBlackIterator(const Tree& tree, const NodeP &node) : _tree(tree), _node(node) { }
			RedBlackIterator(const RedBlackIterator &rbtIt) : _tree(rbtIt._tree), _node(rbtIt._node) { }


			//	assignation

			RedBlackIterator	&operator=(const RedBlackIterator &rbtIt)
			{
				if (this != &rbtIt)
				{
					_tree = rbtIt._tree;
					_node = rbtIt._node;
				}
				return (*this);
			}


			//	access

			reference 			operator*() const
			{
				return (*(_node->valuePtr()));
			}

			pointer 			operator->() const
			{
				return (_node->valuePtr());
			}
			

			//	move pointer

			RedBlackIterator&	operator++()
			{
				_node = _tree.nextNode(_node);
				return (*this);
			}

			RedBlackIterator	operator++(int) 
			{
				RedBlackIterator	newIt = *this;

				_node = _tree.nextNode(_node);
				return (newIt);
			}

			RedBlackIterator&	operator--() 
			{
				_node = _tree.prevNode(_node);
				return (*this);
			}

			RedBlackIterator	operator--(int) 
			{
				RedBlackIterator	newIt = *this;
				
				_node = _tree.prevNode(_node);
				return (newIt);
			}


			//	get pointer

			const NodeP&		base() const 
			{
				return (_node);
			}


			//	compare

			friend bool	operator==(const RedBlackIterator &it1, const RedBlackIterator &it2)
			{
				return (it1._node == it2._node);
			}

			friend bool	operator!=(const RedBlackIterator &it1, const RedBlackIterator &it2)
			{
				return (it1._node != it2._node);
			}
	};

	/*
	**		COMPARISONS
	*/

	template <typename T, class Compare>
	inline bool operator==(const RedBlackIterator<T, Compare>& lhs, const RedBlackIterator<T, Compare>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T, class Compare>
	inline bool operator!=(const RedBlackIterator<T, Compare>& lhs, const RedBlackIterator<T, Compare>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename T, class Compare>
	inline bool operator<(const RedBlackIterator<T, Compare>& lhs, const RedBlackIterator<T, Compare>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T, class Compare>
	inline bool operator<=(const RedBlackIterator<T, Compare>& lhs, const RedBlackIterator<T, Compare>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T, class Compare>
	inline bool operator>(const RedBlackIterator<T, Compare>& lhs, const RedBlackIterator<T, Compare>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	
	template <typename T, class Compare>
	inline bool operator>=(const RedBlackIterator<T, Compare>& lhs, const RedBlackIterator<T, Compare>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
}

#endif
