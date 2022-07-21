/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:50:32 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/21 18:57:22 by lle-briq         ###   ########.fr       */
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

			TreeP	_tree;
			NodeP	_node;


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
					_tree->print();
				}
			}

			RedBlackIterator(const RedBlackIterator &rbtIt)
			{
				*this = rbtIt;
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
					if (LOG >= LOG_ALL)
					{
						std::cerr <<  "assignation : node=" << _node << " in tree" << std::endl;
						_tree->print();
					}
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
				_node = _tree->nextNode(_node);
				return (*this);
			}

			RedBlackIterator	operator++(int) 
			{
				RedBlackIterator	newIt = *this;

				_node = _tree->nextNode(_node);
				return (newIt);
			}

			RedBlackIterator&	operator--() 
			{
				_node = _tree->prevNode(_node);
				return (*this);
			}

			RedBlackIterator	operator--(int) 
			{
				RedBlackIterator	newIt = *this;
				
				_node = _tree->prevNode(_node);
				return (newIt);
			}

			NodeP				base(void) const
			{
				return (_node);
			}


			//	compare

			friend bool	operator==(const RedBlackIterator &it1, const RedBlackIterator &it2)
			{
				return ((it1._node->isLeaf && it2._node->isLeaf) ||
					(it1._tree->areEqual(it1._node->value, it2._node->value)
					&& !it1._node->isLeaf && !it2._node->isLeaf));
			}

			friend bool	operator!=(const RedBlackIterator &it1, const RedBlackIterator &it2)
			{
				return (!(operator==(it1, it2)));
			}
	};
}

#endif
