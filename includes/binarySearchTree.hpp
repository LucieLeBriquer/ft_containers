/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:34:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/28 17:21:15 by lle-briq         ###   ########.fr       */
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
	template < class T, class Compare, class Alloc = std::allocator<T> >
	class binarySearchTree
	{
		private:

			typedef ft::Node<T> Node;

			Node	*_node;
			Compare	_cmp;
			Alloc	_alloc;

		public:
			binarySearchTree(const Compare& comp = Compare(), const Alloc& alloc = Alloc()) :
				_node(NULL), _cmp(comp), _alloc(alloc)
			{
				return ;
			}
	};
}

#endif
