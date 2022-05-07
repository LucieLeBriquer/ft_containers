/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:35:09 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/07 18:48:00 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUALHPP
# define EQUAL_HPP
# include "is_integral.hpp"

namespace ft
{
	struct __true_type { };
  	struct __false_type { };

  	template<bool> struct truth_type
    { typedef __false_type type; };

  	template<> struct truth_type<true>
	{ typedef __true_type type; };

	template<typename _Tp>
    struct is_pointer
    {
		enum { value = 0 };
		typedef __false_type type;
    };

  	template<typename _Tp>
    struct is_pointer<_Tp*>
    {
      enum { value = 1 };
      typedef __true_type type;
    };

  	template<bool b>
    struct __equal
    {
		template<typename It1, typename It2>
		static bool equal(It1 __first1, It1 __last1, It2 __first2)
		{
			for (; __first1 != __last1; ++__first1, (void) ++__first2)
				if (!(*__first1 == *__first2))
			return (false);
		return (true);
		}
    };

  	template<>
    struct __equal<true>
    {
		template<typename T>
		static bool equal(const T* __first1, const T* __last1, const T* __first2)
		{
			if (const size_t __len = (__last1 - __first1))
				return !(__builtin_memcmp(__first1, __first2, sizeof(T) * __len));
			return (true);
		}
    };

	template<typename It1, typename It2>
	bool equal_aux(It1 __first1, It1 __last1, It2 __first2)
    {
      typedef typename iterator_traits<It1>::value_type ValueType1;
      typedef typename iterator_traits<It2>::value_type ValueType2;
      const bool simple = ((is_integeral<ValueType1>::value
			      || is_pointer<ValueType1>::value)
			     && is_pointer<It1>::value
			     && is_pointer<It2>::value
			     && are_same<ValueType1, ValueType2>::value);

      return std::__equal<simple>::equal(__first1, __last1, __first2);
    }


	template<typename IT1, typename IT2>
    bool
    equal(IT1 __first1, IT1 __last1, IT2 __first2)
    {
		return std::equal_aux(std::__niter_base(__first1),
			      std::__niter_base(__last1),
			      std::__niter_base(__first2));
    }
}

#endif
