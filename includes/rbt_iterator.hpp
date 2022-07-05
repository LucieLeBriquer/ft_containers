/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:50:32 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/29 18:19:37 by lle-briq         ###   ########.fr       */
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
			typedef RedBlackTree<T, Compare> Tree;
			typedef Node<T> *NodeP;
			Tree	_tree;
			NodeP	_node;

		public:
			typedef typename std::random_access_iterator_tag	iterator_category;
			typedef T											value_type;
			typedef typename std::ptrdiff_t						difference_type;
			typedef T*   										pointer;
			typedef T&											reference;

			// constructors
			RedBlackIterator() : _tree(Tree()), _node(_tree.getRoot()) { }
			RedBlackIterator(const Tree& tree) : _tree(tree), _node(_tree.getRoot()) { }
			RedBlackIterator(const Tree& tree, const NodeP &node) : _tree(tree), _node(node) { }
			RedBlackIterator(const RedBlackIterator &rbtIt) : _tree(rbtIt._tree), _node(rbtIt._node) { }

			RedBlackIterator	&operator=(const RedBlackIterator &rbtIt)
			{
				if (this != &rbtIt)
				{
					_tree = rbtIt._tree;
					_node = rbtIt._node;
				}
				return (*this);
			}

			reference 			operator*() const { return (*_node); }
			pointer 			operator->() const { return (&(_node->value)); }
			
			RedBlackIterator&	operator++()
			{
				_node = _tree.nextNode(_node);
				return (*this);
			}

			RedBlackIterator	operator++(int) 
			{
				RedBlackIterator	newIt(_tree, _tree.nextNode(_node));

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
				RedBlackIterator	newIt(_tree, _tree.prevNode(_node));
				
				_node = _tree.prevNode(_node);
				return (newIt);
			}

			const NodeP&		base() const 
			{
				return (_node);
			}

	};

	// comparisons
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
