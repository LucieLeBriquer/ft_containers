/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:50:32 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/28 08:05:22 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP
# include "RedBlackTree.hpp"
# include "iterators_traits.hpp"
# include "global.hpp"

namespace ft
{
	template <typename T, class Compare>
	class RedBlackIterator
    {
		protected:
		
			//	typedefs

			typedef RedBlackTree<T, Compare> *TreeP;
			typedef Node<T> *NodeP;


			//	member objects

			//TreeP	_tree;
			//NodeP	_node;
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

			typedef T								value_type;
			typedef T&								reference;
			typedef T*   							pointer;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;


			//	constructors

			RedBlackIterator() : _tree(NULL), _node(NULL)
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[RedBlackIterator] " << END << "constructor" << std::endl;
			}
			
			RedBlackIterator(const TreeP& tree, const NodeP &node) : _tree(tree), _node(node)
			{
				if (LOG >= LOG_ALL)
				{
					std::cerr << GREEN << "[RedBlackIterator] " << END << "tree constructor" << std::endl;
					std::cerr <<  "node=" << _node << " in tree" << std::endl;
					_getTree()->print();
				}
			}

			// RedBlackIterator(const RedBlackIterator &rbtIt)
			// {
			// 	*this = rbtIt;
			// 	if (LOG >= LOG_ALL)
			// 		std::cerr << GREEN << "[RedBlackIterator] " << END << "copy constructor" << std::endl;
			// }
			
			template<typename U>
			RedBlackIterator(const RedBlackIterator<U, Compare> &rbtIt, typename ft::enable_if< (ft::are_const_same<T, U>::value), T>::type* = 0) :
				_tree(rbtIt.baseTree()),
				_node(rbtIt.baseNode())
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[RedBlackIterator] " << END << "copy constructor" << std::endl;

			}

			//	assignation

			RedBlackIterator	&operator=(const RedBlackIterator &rbtIt)
			{
				if (this != &rbtIt)
				{
					if (LOG >= LOG_ALL)
						std::cerr << YELLOW << "[RedBlackIterator] " << END << "assignation" << std::endl;
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

			// reference	operator[](difference_type n) const
			// {
			// 	if (n >= 0)
			// 		return (*( _tree->nextNode(_node, n)->valuePtr()));
			// 	return (*( _tree->prevNode(_node, -n)->valuePtr()));
			// }

			// RedBlackIterator&	operator+=(difference_type n)
			// {
			// 	if (n >= 0)
			// 		_node = _tree->nextNode(_node, n);
			// 	else
			// 		_node = _tree->prevNode(_node, -n);
			// 	return (*this);
			// }

			// RedBlackIterator		operator+(difference_type n) const
			// {
			// 	NodeP	newPtr;

			// 	if (n >= 0)
			// 		newPtr = _tree->nextNode(_node, n);
			// 	else
			// 		newPtr = _tree->prevNode(_node, -n);
			// 	return (RedBlackIterator(_tree, newPtr));
			// }

			// RedBlackIterator&	operator-=(difference_type n)
			// {
			// 	if (n >= 0)
			// 		_node = _tree->prevNode(_node, n);
			// 	else
			// 		_node = _tree->nextNode(_node, -n);
			// 	return (*this);
			// }

			// RedBlackIterator	operator-(difference_type n) const
			// {
			// 	NodeP	newPtr;

			// 	if (n >= 0)
			// 		newPtr = _tree->prevNode(_node, n);
			// 	else
			// 		newPtr = _tree->nextNode(_node, -n);

			// 	return (RedBlackIterator(_tree, newPtr));
			// }

			void	*baseNode(void) const
			{
			 	return (_node);
			}

			void	*baseTree(void) const
			{
			 	return (_tree);
			}


			//	compare

			// friend bool	operator==(const RedBlackIterator &it1, const RedBlackIterator &it2)
			// {
			// 	return ((it1._node->isLeaf && it2._node->isLeaf) ||
			// 		(it1._tree->areEqual(it1._node->value, it2._node->value)
			// 		&& !it1._node->isLeaf && !it2._node->isLeaf));
			// }

			// friend bool	operator!=(const RedBlackIterator &it1, const RedBlackIterator &it2)
			// {
			// 	return (!(operator==(it1, it2)));
			// }
	};

	template<typename T, typename U, class Compare>
	bool	operator==(const RedBlackIterator<T, Compare> &it1, const RedBlackIterator<U, Compare> &it2)
	{
		Node<T>	*nodeT = reinterpret_cast<Node<T> *>(it1.baseNode());
		Node<U>	*nodeU = reinterpret_cast<Node<U> *>(it2.baseNode());
		RedBlackTree<T, Compare> *treeT = reinterpret_cast<RedBlackTree<T, Compare> *>(it1.baseTree());

		return ((nodeT->isLeaf && nodeU->isLeaf) ||
			(treeT->areEqual(nodeT->value, nodeU->value)
			&& !nodeT->isLeaf && !nodeU->isLeaf));
	}

	template<typename T, typename U, class Compare>
	bool	operator!=(const RedBlackIterator<T, Compare> &it1, const RedBlackIterator<U, Compare> &it2)
	{
		return (!(operator==(it1, it2)));
	}
}

#endif
