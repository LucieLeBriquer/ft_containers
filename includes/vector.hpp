/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:36:29 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/11 14:36:17 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "normal_iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include <memory>
#include <iostream>

namespace ft
{
  	template<typename T>
	class vector
    {

    public:
    	typedef T											value_type;
      	typedef std::allocator<T>							allocator_type;
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
		pointer					_base;
		size_type				_capacity;
		size_type				_size;
		allocator_type			_alloc = allocator_type();

		static size_type	_closestPow2(size_type n)
		{
			size_type	i = 1;

			while (i < n)
				i *= 2;
			return (i);
		}

	public:
		
		// constructors and destructor
      	explicit vector(void) : _base(NULL), _capacity(0), _size(0) { }
		
		explicit vector(size_type n, const value_type& val = value_type()) :
			_base(NULL), _capacity(0), _size(0)
		{
			std::cout << "[Vector] assign constructor" << std::endl;
			assign(n, val);
		}

		template <class InputIterator, ft::enable_if< !ft::is_integral<InputIterator>::value > = false>
		vector(InputIterator first, InputIterator last):
			_base(NULL), _capacity(0), _size(0)
		{
			size_type	len;

			len = last - first;
			reserve(len);
			assign(first, last);
		}

		vector (const vector& v)
		{

		}

		virtual ~vector()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_base + i);
			_alloc.deallocate(_base, _size);
		}


		// iterators

		// capacity

		void	reserve(size_type n)
		{
			pointer	copy = _base;

			if (_capacity >= n)
				return ;
			_capacity = _closestPow2(n);	
			_base = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_base + i, *(copy + i));
			
			for (size_type i = 0; i < _size; i++)
				std::cout << *(_base + i) << " ";
			std::cout << _size << "/" << _capacity << std::endl;
		}

		// element access

		// modifiers
		template <class InputIterator, ft::enable_if< !ft::is_integral<InputIterator>::value > = false>
  		void assign(InputIterator first, InputIterator last)
		{
			size_type	len;

			len = last - first;
			reserve(len);
		}
		
		void assign(size_type n, const value_type& val)
		{
			reserve(n);
			clear();
			_size = n;
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_base + i, val);
		}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_base + i);
			_size = 0;
		}


    };
}

#endif
