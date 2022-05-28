/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:34:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/28 16:41:52 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP
# include "equal.hpp"
# include "pair.hpp"
# include <memory>

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>,
		class Alloc = std::allocator< ft::pair<const Key,T> > >
	class tree
	{
	public:
		tree(void) { };
		tree(const key_compare& comp = Compare(), const allocator_type& alloc = Alloc()) { };
	};
}

#endif
