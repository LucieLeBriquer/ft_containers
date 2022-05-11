/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:36:29 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/11 12:59:19 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "normal_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
  	template<typename T, typename Alloc = std::allocator<T> >
	class vector
    {

    public:
    	typedef T											value_type;
      	typedef Alloc										allocator_type;
    	typedef typename allocator_type::pointer			pointer;
    	typedef typename allocator_type::const_pointer		const_pointer;
      	typedef typename allocator_type::reference			reference;
      	typedef typename allocator_type::const_reference	const_reference;
      	typedef normal_iterator<pointer, vector>			iterator;
      	typedef normal_iterator<const_pointer, vector>		const_iterator;
      	typedef reverse_iterator<const_iterator>			const_reverse_iterator;
      	typedef reverse_iterator<iterator>					reverse_iterator;
      	typedef size_t										size_type;
      	typedef ptrdiff_t									difference_type;
		
	protected:
		pointer		_base;
		size_type	_capacity;
		size_type	_size;

	public:

      	explicit vector(const allocator_type &a = allocator_type()) : _base(a) { }

    };
}

#endif
