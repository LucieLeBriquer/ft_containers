/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:40:15 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/30 18:52:43 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
# define ITERATORS_TRAITS_HPP
# include "iterator.hpp"
# include <iterator>

// https://www.cplusplus.com/reference/iterator/iterator_traits/

namespace ft {

	template< class Iterator >
	class iterator_traits {
		public:
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type 			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer 				pointer;
			typedef typename Iterator::reference 			reference;
	};
			
	template< class T >
	class iterator_traits<T*> {
		public:
			typedef std::random_access_iterator_tag			iterator_category;
			typedef T										value_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T* 										pointer;
			typedef T&										reference;
	};
			
	template< class T >
	class iterator_traits<const T*> {
		public:
			typedef std::random_access_iterator_tag			iterator_category;
			typedef T										value_type;
			typedef std::ptrdiff_t							difference_type;
			typedef const T* 								pointer;
			typedef const T&								reference;
	};
}

#endif
