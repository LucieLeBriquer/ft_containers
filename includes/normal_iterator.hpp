/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:18:53 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/27 14:50:31 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_ITERATOR_HPP
# define NORMAL_ITERATOR_HPP
# include "iterator.hpp"

namespace ft {

	template<typename Iterator, typename Container>
    class normal_iterator
    {
		protected:
			Iterator	_current;

		typedef iterator_traits<Iterator>		_traitsType;

		public:
			typedef Iterator									iterator_type;
			typedef typename _traitsType::iterator_category		iterator_category;
			typedef typename _traitsType::value_type			value_type;
			typedef typename _traitsType::difference_type		difference_type;
			typedef typename _traitsType::reference				reference;
			typedef typename _traitsType::pointer   			pointer;

			// constructors
			normal_iterator() : _current(Iterator()) { }
			explicit normal_iterator(const Iterator& iterator) : _current(iterator) { }

			// allow iterator to const_iterator conversion
			template<typename Iter>
			normal_iterator(const normal_iterator< Iter, typename ft::enable_if< (ft::are_same<Iter, typename Container::pointer>::value), Container>::type >& iterator) 
				: _current(iterator.base()) { }

			reference operator*() const { return *_current; }
			pointer operator->() const { return _current; }
			
			normal_iterator&	operator++() {
				++_current;
				return (*this);
			}

			normal_iterator	operator++(int) 
			{
				return (normal_iterator(_current++));
			}

			normal_iterator&	operator--() 
			{
				--_current;
				return (*this);
			}

			normal_iterator	operator--(int) 
			{
				return (normal_iterator(_current--));
			}

			reference	operator[](difference_type n) const
			{
				return _current[n];
			}

			normal_iterator&	operator+=(difference_type n)
			{
				_current += n;
				return (*this);
			}

			normal_iterator		operator+(difference_type n) const
			{
				return (normal_iterator(_current + n));
			}

			normal_iterator&	operator-=(difference_type n)
			{
				_current -= n;
				return *this;
			}

			normal_iterator		operator-(difference_type n) const
			{
				return (normal_iterator(_current - n));
			}

			const Iterator&		base() const 
			{
				return (_current);
			}

	};

	// comparisons

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool operator==(const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator==(const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator!=(const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator!=(const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator<(const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool	operator<(const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator>(const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator>(const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator<=(const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator<=(const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool	operator>=(const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename Iterator, typename Container>
	inline bool	operator>=(const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline typename normal_iterator<IteratorL, Container>::difference_type 
		operator-(const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<typename Iterator, typename Container>
	inline typename normal_iterator<Iterator, Container>::difference_type
		operator-(const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<typename Iterator, typename Container>
	inline normal_iterator<Iterator, Container>	
		operator+(typename normal_iterator<Iterator, Container>::difference_type n, const normal_iterator<Iterator, Container>& iterator)
	{
		return (normal_iterator<Iterator, Container>(iterator.base() + n));
	}
}

#endif
