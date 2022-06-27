/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:50:32 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/27 19:32:49 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP
# include "RedBlackTree.hpp"
# include "iterators_traits.hpp"

namespace ft
{
	template <typename T>
	class RedBlackIterator
    {
		protected:
			typedef Node<T> *NodeP;
			NodeP	_current;

		public:
			typedef NodeP										iterator_type;
			typedef typename std::random_access_iterator_tag	iterator_category;
			typedef typename T									value_type;
			typedef typename std::ptrdiff_t						difference_type;
			typedef typename T&   								pointer;
			typedef typename T*									reference;

			// constructors
			RedBlackIterator() : _current(NodeP()) { }
			RedBlackIterator(const NodeP& node) : _current(node) { }

			reference 			operator*() const { return _current->value; }
			pointer 			operator->() const { return &(_current->value); }
			
			RedBlackIterator&	operator++()
			{
				RedBlackIterator	copy(*this);
				_current = RedBlackTree::nextNode(_current);
				return (copy);
			}

			RedBlackIterator	operator++(int) 
			{
				_current = RedBlackTree::nextNode(_current);
				return (*this);
			}

			RedBlackIterator&	operator--() 
			{
				RedBlackIterator	copy(*this);
				_current = RedBlackTree::prevNode(_current);
				return (copy);
			}

			RedBlackIterator	operator--(int) 
			{
				_current = RedBlackTree::prevNode(_current);
				return (*this);
			}

			iterator_type		base() const
			{
				return (_current);
			}
	};

	template <typename T>
	bool operator==(const RedBlackIterator<T>& it1, const RedBlackIterator<T>& it2)
    {
		return (it1.base() == it2.base());
	}

	template <typename T>
	bool operator==(const RedBlackIterator<T>& it1, const RedBlackIterator<T>& it2)
    {
		return (it1.base() != it2.base());
	}
}

#endif
