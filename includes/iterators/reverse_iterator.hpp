/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:55:35 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/08 10:36:28 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator.hpp"

namespace ft
{
	/*
	**		CLASSIC reverse iterator
	*/

	template<typename Iterator>
    class reverseIterator : public iterator<typename iterator_traits<Iterator>::value_type,
		    								typename iterator_traits<Iterator>::difference_type,
		      								typename iterator_traits<Iterator>::pointer,
                    						typename iterator_traits<Iterator>::reference>
    {
    	protected:
     		Iterator _current;

      		typedef iterator_traits<Iterator>		traitsType;

   		public:
			typedef Iterator								iterator_type;
			typedef typename traitsType::difference_type	difference_type;
			typedef typename traitsType::pointer			pointer;
			typedef typename traitsType::reference			reference;

		private:
      		template<typename T>
			static T* 		_toPointer(T* p) { return p; }
			
			template<typename T>
			static pointer	_toPointer(T t) { return t.operator->(); }
		
		public:
			reverseIterator() : _current() { }	
			reverseIterator(iterator_type iterator) : _current(iterator) {	}
			reverseIterator(const reverseIterator &rev_iterator) : _current(rev_iterator._current) { }
			
			template<typename Iter>
			reverseIterator(const reverseIterator<Iter>& rev_it) : _current(rev_it.base()) { }

			reverseIterator	&operator=(const reverseIterator &rev_iterator)
			{
				_current = rev_iterator._current;
				return (*this);
			}

			iterator_type			base() const
			{
				return (_current);
			}

      		reference	operator*() const
     		{
				Iterator	save = _current;
				return (*(--save));
      		}

			pointer		operator->() const
			{
				Iterator	save = _current;
				--save;
				return (_toPointer(save));
      		}
			
			reverseIterator&	operator++()
			{
				--_current;
				return (*this);
      		}
			
			reverseIterator	operator++(int)
      		{
				reverseIterator	save(*this);
				--_current;
				return (save);
      		}
			
			reverseIterator&	operator--()
			{
				++_current;
				return (*this);
      		}
			
			reverseIterator	operator--(int)
      		{
				reverseIterator	save(*this);
				
				++_current;
				return (save);
      		}
			
			reverseIterator	operator+(difference_type n) const
      		{
				return (reverseIterator(_current - n));
			}
			
			reverseIterator&	operator+=(difference_type n)
      		{
				_current -= n;
				return (*this);
      		}

			reverseIterator	operator-(difference_type n) const
      		{
				return (reverseIterator(_current + n));
			}
			
			reverseIterator&	operator-=(difference_type n)
      		{
				_current += n;
				return (*this);
      		}
			
			reference	operator[](difference_type n) const
			{
				return (*(*this + n));
			}    
    };


	/*
	**		COMPARISONS between reverse iterators
	*/
	
	template<typename Iterator>
	inline bool	operator==(const reverseIterator<Iterator>& iteratorL,	const reverseIterator<Iterator>& iteratorR)
	{
		return (iteratorL.base() == iteratorR.base());
	}

	template<typename Iterator>
	inline bool	operator<(const reverseIterator<Iterator>& iteratorL, const reverseIterator<Iterator>& iteratorR)
	{
		return (iteratorR.base() < iteratorL.base());
	}

	template<typename Iterator>
	inline bool	operator!=(const reverseIterator<Iterator>& iteratorL, const reverseIterator<Iterator>& iteratorR)
	{
		return (!(iteratorL.base() == iteratorR.base()));
	}

	template<typename Iterator>
	inline bool	operator>(const reverseIterator<Iterator>& iteratorL, const reverseIterator<Iterator>& iteratorR)
	{ 
		return (iteratorR < iteratorL);
	}

	template<typename Iterator>
	inline bool	operator<=(const reverseIterator<Iterator>& iteratorL, const reverseIterator<Iterator>& iteratorR)
	{
		return (!(iteratorR < iteratorL));
	}

	template<typename Iterator>
	inline bool	operator>=(const reverseIterator<Iterator>& iteratorL, const reverseIterator<Iterator>& iteratorR)
	{
		return (!(iteratorL < iteratorR));
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator==(const reverseIterator<IteratorL>& iteratorL, const reverseIterator<IteratorR>& iteratorR)
	{
		return (iteratorL.base() == iteratorR.base());
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator<(const reverseIterator<IteratorL>& iteratorL, const reverseIterator<IteratorR>& iteratorR)
	{
		return (iteratorR.base() < iteratorL.base());
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator!=(const reverseIterator<IteratorL>& iteratorL, const reverseIterator<IteratorR>& iteratorR)
	{
		return (!(iteratorL == iteratorR));
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator>(const reverseIterator<IteratorL>& iteratorL,	const reverseIterator<IteratorR>& iteratorR)
	{
		return (iteratorR < iteratorL);
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator<=(const reverseIterator<IteratorL>& iteratorL, const reverseIterator<IteratorR>& iteratorR)
	{
		return (!(iteratorR < iteratorL));
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator>=(const reverseIterator<IteratorL>& iteratorL, const reverseIterator<IteratorR>& iteratorR)
	{
		return (!(iteratorL < iteratorR));
	}

	template<typename Iterator>    inline typename reverseIterator<Iterator>::difference_type
    	operator-(const reverseIterator<Iterator>& iteratorL, const reverseIterator<Iterator>& iteratorR)
    {
		return (iteratorR.base() - iteratorL.base());
	}

	template<typename IteratorL, typename IteratorR>	inline typename reverseIterator<IteratorL>::difference_type
	  	operator-(const reverseIterator<IteratorL>& iteratorL, const reverseIterator<IteratorR>& iteratorR)
    {
		return (iteratorR.base() - iteratorL.base());
	}
			
  	template<typename Iterator>	inline reverseIterator<Iterator>
    	operator+(typename reverseIterator<Iterator>::difference_type n, const reverseIterator<Iterator>& iteratorL)
    {
		return reverseIterator<Iterator>(iteratorL.base() - n);
	}

}

#endif
