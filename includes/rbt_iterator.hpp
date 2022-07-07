/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:50:32 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/07 18:21:37 by lle-briq         ###   ########.fr       */
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

			RedBlackIterator() : _tree(Tree()), _node(_tree.getRoot())
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[RedBlackIterator] " << END << "constructor" << std::endl;
			}
			
			RedBlackIterator(const Tree& tree, const NodeP &node) : _tree(tree), _node(node)
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[RedBlackIterator] " << END << "tree constructor" << std::endl;	
			}

			RedBlackIterator(const RedBlackIterator &rbtIt) : _tree(rbtIt._tree), _node(rbtIt._node)
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[RedBlackIterator] " << END << "copy constructor" << std::endl;
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
				return (*(_node->valuePtr()));
			}

			pointer 			operator->() const
			{
				return (_node->valuePtr());
			}
			

			//	move pointer

			RedBlackIterator&	operator++()
			{
				std::cerr << "++(" << _node;
				_node = _tree.nextNode(_node);
				std::cerr << ") leads to " << _node << "[" << _node->value.first << "]" << std::endl;
				std::cerr << "\tleaf = " << _tree.getLeaf() << std::endl;
				_tree.print();
				std::cout << std::endl;
				return (*this);
			}

			RedBlackIterator	operator++(int) 
			{
				RedBlackIterator	newIt = *this;

				std::cerr << "++(" << _node;
				_node = _tree.nextNode(_node);
				std::cerr << ") leads to " << _node << "[" << _node->value.first << "]" << std::endl;
				std::cerr << "\tleaf = " << _tree.getLeaf() << std::endl;
				_tree.print();
				std::cout << std::endl;
				return (newIt);
			}

			RedBlackIterator&	operator--() 
			{
				std::cerr << "--(" << _node;
				_node = _tree.prevNode(_node);
				std::cerr << ") leads to " << _node << "[" << _node->value.first << "]" << std::endl;
				std::cerr << "\tleaf = " << _tree.getLeaf() << std::endl;
				_tree.print();
				std::cout << std::endl;
				return (*this);
			}

			RedBlackIterator	operator--(int) 
			{
				RedBlackIterator	newIt = *this;
				
				std::cerr << "--(" << _node;
				_node = _tree.prevNode(_node);
				std::cerr << ") leads to " << _node << "[" << _node->value.first << "]" << std::endl;
				std::cerr << "\tleaf = " << _tree.getLeaf() << std::endl;
				_tree.print();
				std::cout << std::endl;
				return (newIt);
			}


			//	get pointer

			const NodeP&		base() const 
			{
				return (_node);
			}


			//	compare

			/*friend bool	operator==(const RedBlackIterator &it1, const RedBlackIterator &it2)
			{
				std::cerr << "here" << std::endl;
				std::cerr << "it1 " << it1._node->value.first << std::endl;
				std::cerr << "it2 " << it2._node->value.first << std::endl;
				return (it1._node == it2._node);<
			}

			friend bool	operator!=(const RedBlackIterator &it1, const RedBlackIterator &it2)
			{
				std::cerr << "here" << std::endl;
				std::cerr << "it1 " << it1._node->value.first << std::endl;
				std::cerr << "it2 " << it2._node->value.first << std::endl;
				return (it1._node != it2._node);
			}*/
	};

	/*
	**		COMPARISONS
	*/

	template <typename T, class Compare>
	inline bool operator==(const RedBlackIterator<T, Compare>& lhs, const RedBlackIterator<T, Compare>& rhs)
	{
		std::cerr << "==()" << std::endl;
		std::cerr << "lhs " << lhs.base()->value.first << "\tlhs.base() " << lhs.base() << std::endl;
		std::cerr << "rhs " << rhs.base()->value.first << "rhs.base() " << rhs.base() << std::endl;
		return (lhs.base() == rhs.base());
	}

	template <typename T, class Compare>
	inline bool operator!=(const RedBlackIterator<T, Compare>& lhs, const RedBlackIterator<T, Compare>& rhs)
	{
		std::cerr << "!=()" << std::endl;
		std::cerr << "lhs " << lhs.base()->value.first << std::endl;
		std::cerr << "rhs " << rhs.base()->value.first << std::endl;
		std::cerr << "lhs.base() " << lhs.base() << std::endl;
		std::cerr << "rhs.base() " << rhs.base() << std::endl;
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
