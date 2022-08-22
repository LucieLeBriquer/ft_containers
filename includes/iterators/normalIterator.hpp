/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:22:06 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/22 19:22:06 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMALITERATOR_HPP
# define NORMALITERATOR_HPP
# include "iterator.hpp"
# include <iostream>

namespace ft
{
	template<typename Iterator, typename Container>
    class normalIterator
    {
		protected:
			Iterator	_current;

			typedef iterator_traits<Iterator> _traitsType;

		public:
			typedef Iterator									iterator_type;
			typedef typename _traitsType::iterator_category		iterator_category;
			typedef typename _traitsType::value_type			value_type;
			typedef typename _traitsType::difference_type		difference_type;
			typedef typename _traitsType::reference				reference;
			typedef typename _traitsType::pointer   			pointer;

			// constructors
			normalIterator() : _current(Iterator()) { }

			normalIterator(const Iterator& iterator) : _current(iterator) { }

			template<typename Iter>
			normalIterator(const normalIterator< Iter, typename ft::enable_if< (ft::are_same<Iter, typename Container::pointer>::value), Container>::type >& iterator) 
				: _current(iterator.base()) { }
			
			template<typename Iter>
			normalIterator(const normalIterator< Iter, typename ft::enable_if< (ft::are_const_same<typename Iter::value_type, value_type>::value), Container>::type >& iterator) 
				: _current(iterator.base()) { }

			virtual ~normalIterator(void) { }

			reference operator*() const
			{
				return (*_current);
			}

			pointer operator->() const
			{
				return (&(*_current));
			}
			
			normalIterator&	operator++() {
				++_current;
				return (*this);
			}

			normalIterator	operator++(int) 
			{
				return (normalIterator(_current++));
			}

			normalIterator&	operator--() 
			{
				--_current;
				return (*this);
			}

			normalIterator	operator--(int) 
			{
				return (normalIterator(_current--));
			}

			reference	operator[](difference_type n) const
			{
				return (_current[n]);
			}

			normalIterator&	operator+=(difference_type n)
			{
				_current += n;
				return (*this);
			}

			normalIterator		operator+(difference_type n) const
			{
				return (normalIterator(_current + n));
			}

			normalIterator&	operator-=(difference_type n)
			{
				_current -= n;
				return (*this);
			}

			normalIterator		operator-(difference_type n) const
			{
				return (normalIterator(_current - n));
			}

			const Iterator&		base() const 
			{
				return (_current);
			}

	};

	// comparisons

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool operator==(const normalIterator<IteratorL, Container>& lhs, const normalIterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator==(const normalIterator<Iterator, Container>& lhs, const normalIterator<Iterator, Container>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator!=(const normalIterator<IteratorL, Container>& lhs, const normalIterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator!=(const normalIterator<Iterator, Container>& lhs, const normalIterator<Iterator, Container>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator<(const normalIterator<IteratorL, Container>& lhs, const normalIterator<IteratorR, Container>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool	operator<(const normalIterator<Iterator, Container>& lhs, const normalIterator<Iterator, Container>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator>(const normalIterator<IteratorL, Container>& lhs, const normalIterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator>(const normalIterator<Iterator, Container>& lhs, const normalIterator<Iterator, Container>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator<=(const normalIterator<IteratorL, Container>& lhs, const normalIterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator<=(const normalIterator<Iterator, Container>& lhs, const normalIterator<Iterator, Container>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator>=(const normalIterator<IteratorL, Container>& lhs, const normalIterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator>=(const normalIterator<Iterator, Container>& lhs, const normalIterator<Iterator, Container>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline typename normalIterator<IteratorL, Container>::difference_type 
		operator-(const normalIterator<IteratorL, Container>& lhs, const normalIterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<typename Iterator, typename Container>
	inline typename normalIterator<Iterator, Container>::difference_type
		operator-(const normalIterator<Iterator, Container>& lhs, const normalIterator<Iterator, Container>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<typename Iterator, typename Container>
	inline normalIterator<Iterator, Container>	
		operator+(typename normalIterator<Iterator, Container>::difference_type n, const normalIterator<Iterator, Container>& iterator)
	{
		return (normalIterator<Iterator, Container>(iterator.base() + n));
	}
}

#endif
