/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_STL.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:55:35 by lle-briq          #+#    #+#             */
/*   Updated: 2022/04/02 17:12:30 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
	template<typename Iterator>
    class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
											typename iterator_traits<Iterator>::value_type,
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
			reverse_iterator() : _current() { }	
			reverse_iterator(iterator_type iterator) : _current(iterator) { }
			reverse_iterator(const reverse_iterator & rev_iterator) : _current(rev_iterator._current) { }

			template<typename Iter>	reverse_iterator(const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) { }

			iterator_type			base() const	{ return (_current); }

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
			
			reverse_iterator&	operator++()
			{
				--_current;
				return (*this);
      		}
			
			reverse_iterator	operator++(int)
      		{
				reverse_iterator	save = *this;
				--_current;
				return (save);
      		}
			
			reverse_iterator&	operator--()
			{
				++_current;
				return (*this);
      		}
			
			reverse_iterator	operator--(int)
      		{
				reverse_iterator	save = *this;
				++_current;
				return (save);
      		}
			
			reverse_iterator	operator+(difference_type n) const
      		{
				return (reverse_iterator(current - n));
			}
			
			reverse_iterator&	operator+=(difference_type n)
      		{
				current -= n;
				return (*this);
      		}

			reverse_iterator	operator-(difference_type n) const
      		{
				return (reverse_iterator(current + n));
			}
			
			reverse_iterator&	operator-=(difference_type n)
      		{
				current += n;
				return (*this);
      		}
			
			reference	operator[](difference_type n) const
			{
				return (*(*this + n));
			}    
    };

	
	template<typename Iterator>
	inline bool	operator==(const reverse_iterator<Iterator>& iteratorL,	const reverse_iterator<Iterator>& iteratorR)
	{
		return (iteratorL.base() == iteratorR.base())
	}

	template<typename Iterator>
	inline bool	operator<(const reverse_iterator<Iterator>& iteratorL, const reverse_iterator<Iterator>& iteratorR)
	{
		return (iteratorR.base() < iteratorL.base());
	}

	template<typename Iterator>
	inline bool	operator!=(const reverse_iterator<Iterator>& iteratorL, const reverse_iterator<Iterator>& iteratorR)
	{
		return (!(iteratorR.base() == iteratorL.base()));
	}

	template<typename Iterator>
	inline bool	operator>(const reverse_iterator<Iterator>& iteratorL, const reverse_iterator<Iterator>& iteratorR)
	{ 
		return (iteratorR < iteratorL);
	}

	template<typename Iterator>
	inline bool	operator<=(const reverse_iterator<Iterator>& iteratorL, const reverse_iterator<Iterator>& iteratorR)
	{
		return (!(iteratorR < iteratorL));
	}

	template<typename Iterator>
	inline bool	operator>=(const reverse_iterator<Iterator>& iteratorL, const reverse_iterator<Iterator>& iteratorR)
	{
		return (!(iteratorL < iteratorR));
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator==(const reverse_iterator<IteratorL>& iteratorL, const reverse_iterator<IteratorR>& iteratorR)
	{
		return (iteratorL.base() == iteratorR.base());
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator<(const reverse_iterator<IteratorL>& iteratorL, const reverse_iterator<IteratorR>& iteratorR)
	{
		return (iteratorR.base() < iteratorL.base());
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator!=(const reverse_iterator<IteratorL>& iteratorL, const reverse_iterator<IteratorR>& iteratorR)
	{
		return (!(iteratorL == iteratorR));
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator>(const reverse_iterator<IteratorL>& iteratorL,	const reverse_iterator<IteratorR>& iteratorR)
	{
		return (iteratorR < iteratorL);
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator<=(const reverse_iterator<IteratorL>& iteratorL, const reverse_iterator<IteratorR>& iteratorR)
	{
		return (!(iteratorR < iteratorL));
	}

	template<typename IteratorL, typename IteratorR>
	inline bool	operator>=(const reverse_iterator<IteratorL>& iteratorL, const reverse_iterator<IteratorR>& iteratorR)
	{
		return (!(iteratorL < iteratorR));
	}

	template<typename Iterator>    inline typename reverse_iterator<Iterator>::difference_type
    	operator-(const reverse_iterator<Iterator>& iteratorL, const reverse_iterator<Iterator>& iteratorR)
    {
		return (iteratorR.base() - iteratorL.base());
	}

	template<typename IteratorL, typename IteratorR>	inline typename reverse_iterator<IteratorL>::difference_type
	  	operator-(const reverse_iterator<IteratorL>& iteratorL, const reverse_iterator<IteratorR>& iteratorR)
    {
		return (iteratorR.base() - iteratorL.base());
	}
			
  	template<typename Iterator>	inline reverse_iterator<Iterator>
    	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& iteratorL)
    {
		return reverse_iterator<Iterator>(iteratorL.base() - n);
	}

}

#endif
