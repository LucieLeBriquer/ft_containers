/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:35:09 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/11 12:17:32 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP
# include "is_integral.hpp"
# include "type_traits.hpp"

namespace ft
{

	template<typename T>
    struct is_pointer
    {
		enum { value = 0 };
		typedef __false_type type;
    };

  	template<typename T>
    struct is_pointer<T*>
    {
		enum { value = 1 };
		typedef __true_type type;
    };

	// equal
  	template<bool b>
    struct equal_aux
    {
		template<typename It1, typename It2>
		static bool equal(It1 first1, It1 last2, It2 first2)
		{
			for (; first1 != last2; ++first1, (void) ++first2)
				if (!(*first1 == *first2))
			return (false);
		return (true);
		}
    };
	
  	template<>
    struct equal_aux<true>
    {
		template<typename T>
		static bool equal(const T* first1, const T* last2, const T* first2)
		{
			if (const size_t len = (last2 - first1))
				return !(__builtin_memcmp(first1, first2, sizeof(T) * len));
			return (true);
		}
    };

	template<typename It1, typename It2>
    bool equal(It1 first1, It1 last2, It2 first2)
    {
		typedef typename iterator_traits<It1>::value_type ValueType1;
		typedef typename iterator_traits<It2>::value_type ValueType2;
		const bool simple = ((is_integral<ValueType1>::value
					|| is_pointer<ValueType1>::value)
					&& is_pointer<It1>::value
					&& is_pointer<It2>::value
					&& are_same<ValueType1, ValueType2>::value);

		return (equal_aux<simple>::equal(first1, last2, first2));
	}

	// lexicographical compare
	template <class It1, class It2>
  	bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class It1, class It2, class Comp>
  	bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2, Comp comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}

#endif
