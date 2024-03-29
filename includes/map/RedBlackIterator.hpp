/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:25:08 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/23 12:13:02 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKITERATOR_HPP
# define REDBLACKITERATOR_HPP
# include "RedBlackTree.hpp"
# include "../iterators/iterators_traits.hpp"
# include "../utils/global.hpp"

namespace ft
{
	template<typename T, bool Const>
	class usefull_types
	{
		public:
			typedef T *pointer_type;
			typedef T &reference_type;
	};

	template<typename T>
	class usefull_types<T, true>
	{
		public:
			typedef const T *pointer_type;
			typedef const T &reference_type;
	};

	template <typename T, class Compare, bool Const>
	class RedBlackIterator
    {
		protected:
		
			//	typedefs

			typedef RedBlackTree<T, Compare>		*TreeP;
			typedef Node<T>							*NodeP;


			//	member objects

			void	*_tree;
			void	*_node;

			TreeP	_getTree(void) const
			{
				return (reinterpret_cast<TreeP>(_tree));
			}

			NodeP	_getNode(void) const
			{
				return (reinterpret_cast<NodeP>(_node));
			}


		public:

			//	typedefs

			typedef T													value_type;
			typedef typename usefull_types<T, Const>::reference_type	reference;
			typedef typename usefull_types<T, Const>::pointer_type		pointer;
			typedef std::bidirectional_iterator_tag						iterator_category;
			typedef std::ptrdiff_t										difference_type;


			//	constructors

			RedBlackIterator() : _tree(NULL), _node(NULL)
			{
				return ;
			}
			
			RedBlackIterator(const TreeP& tree, const NodeP &node) : _tree(tree), _node(node)
			{
				return ;
			}

			template<typename U, bool C>
			RedBlackIterator(const RedBlackIterator<U, Compare, C> &rbtIt,
							typename ft::enable_if< (ft::are_const_same<T, U>::value && ft::sup_or_eq<Const, C>::value), T>::type* = 0) :
				_tree(rbtIt.baseTree()),
				_node(rbtIt.baseNode())
			{
				return ;
			}


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
				return (*(_getNode()->valuePtr()));
			}

			pointer 			operator->() const
			{
				return (_getNode()->valuePtr());
			}
			

			//	move pointer

			RedBlackIterator&	operator++()
			{
				_node = _getTree()->nextNode(_getNode());
				return (*this);
			}

			RedBlackIterator	operator++(int)
			{
				RedBlackIterator	newIt = *this;

				_node = _getTree()->nextNode(_getNode());
				return (newIt);
			}

			RedBlackIterator&	operator--() 
			{
				_node = _getTree()->prevNode(_getNode());
				return (*this);
			}

			RedBlackIterator	operator--(int) 
			{
				RedBlackIterator	newIt = *this;
				
				_node = _getTree()->prevNode(_getNode());
				return (newIt);
			}

			void	*baseNode(void) const
			{
			 	return (_node);
			}

			void	*baseTree(void) const
			{
			 	return (_tree);
			}

			bool	isLeaf(void) const
			{
				if (!_tree)
					return (true);
				NodeP	node = _getNode();
				TreeP	tree = _getTree();

				return (tree->isLeaf(node));
			}
	};

	template<typename T, class Compare1, class Compare2, bool Const1, bool Const2>
	bool	operator==(const RedBlackIterator<T, Compare1, Const1> &it1, 
					const RedBlackIterator<T, Compare2, Const2> &it2)
	{
		Compare1	comp;
		return ((it1.isLeaf() && it2.isLeaf()) 
			|| (!comp(*it1, *it2) && !comp(*it2, *it1) && !it1.isLeaf() && !it2.isLeaf()));
	}

	template<typename T, class Compare1, class Compare2, bool Const1, bool Const2>
	bool	operator!=(const RedBlackIterator<T, Compare1, Const1> &it1,
					const RedBlackIterator<T, Compare2, Const2> &it2)
	{
		return (!(operator==(it1, it2)));
	}

}

#endif
