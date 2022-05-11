/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:06:51 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/07 18:06:51 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template<typename T, T v> struct integral_constant
    {
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
	};

	template<typename T, T v> const T integral_constant<T, v>::value;

  	typedef integral_constant<bool, true>     true_type;
	typedef integral_constant<bool, false>    false_type;

	// remove const
	template<typename T> struct remove_const { typedef T type; };
	template<typename T> struct remove_const<T const> { typedef T type; };

	// define all integral types
	template<typename> struct is_integral_helper : public false_type { };

	template<> struct is_integral_helper<bool> : public true_type { };
	template<> struct is_integral_helper<char> : public true_type { };
	template<> struct is_integral_helper<signed char> : public true_type { };
	template<> struct is_integral_helper<unsigned char> : public true_type { };
	template<> struct is_integral_helper<char16_t> : public true_type { };
	template<> struct is_integral_helper<char32_t> : public true_type { };
	template<> struct is_integral_helper<short> : public true_type { };
	template<> struct is_integral_helper<unsigned short> : public true_type { };
	template<> struct is_integral_helper<int> : public true_type { };
	template<> struct is_integral_helper<unsigned int> : public true_type { };
	template<> struct is_integral_helper<long> : public true_type { };
	template<> struct is_integral_helper<unsigned long> : public true_type { };
	template<> struct is_integral_helper<long long>	: public true_type { };
	template<> struct is_integral_helper<unsigned long long> : public true_type { };

	// is integral
	template<typename T>
	struct is_integral : public is_integral_helper<typename remove_const<T>::type>::type { };
}

#endif
