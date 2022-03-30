/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:59:30 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/30 19:33:31 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSER_ITERATOR_HPP
# define REVERSER_ITERATOR_HPP
# include "iterators_traits.hpp"

// https://www.cplusplus.com/reference/iterator/reverse_iterator/

namespace ft {

	template <class Iterator> class reverse_iterator : public Iterator
	{
		public:
			typedef	Iterator iterator_type;
			typedef	typename iterator_traits<Iterator>::iterator_category 	iterator_category;
			typedef	typename iterator_traits<Iterator>::value_type			value_type;
			typedef	typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef	typename iterator_traits<Iterator>::pointer				pointer;
			typedef	typename iterator_traits<Iterator>::reference			reference;
		
		private:
			iterator_type	_base;

		public:
			// constructors
			reverse_iterator() : Iterator() { return ; }

			explicit reverse_iterator(iterator_type it) : Iterator(it), _base(it)
			{
				return ;
			}

			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : Iterator(rev_it), _base(rev_it)
			{
				return ;
			}

			// member functions
			iterator_type base() const { return (_base); }

			reference 			operator*() const;
			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator&	operator++();
			reverse_iterator	operator++(int);
			reverse_iterator&	operator+=(difference_type n);
			reverse_iterator 	operator-(difference_type n) const;
			reverse_iterator& 	operator--();
			reverse_iterator  	operator--(int);
			reverse_iterator&	operator-=(difference_type n);
			pointer				operator->() const;
			reference			operator[](difference_type n) const;
	};

	template <class Iterator>
  	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
 	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
  	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
  	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
  	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
  	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
  	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);
}

#endif
