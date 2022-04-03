/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:05:48 by lle-briq          #+#    #+#             */
/*   Updated: 2022/04/02 16:05:48 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "iterators_traits.hpp"
# include "enable_if.hpp"

namespace ft
{
	template<typename T, typename distance = std::ptrdiff_t, typename pointerT = T*, typename referenceT = T&>
    struct iterator
    {
      typedef std::random_access_iterator_tag		iterator_category;
      typedef T       								value_type;
      typedef distance								difference_type;
      typedef pointerT								pointer;
      typedef referenceT							reference;
    };
}

#endif
