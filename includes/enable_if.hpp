/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:24:26 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/27 14:31:23 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP
# include "type_traits.hpp"

namespace ft
{
	template<bool B, typename T = void>
	struct enable_if 
	{ };

	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	// compare type equality
  	template<typename T1, typename T2>
    struct are_same
    {
    	enum { value = 0 };
    	typedef __false_type type;
    };

  	template<typename T>
    struct are_same<T, T>
    {
    	enum { value = 1 };
    	typedef __true_type type;
    };

	// compare type equality ignoring const
  	template<typename T1, typename T2>
    struct are_const_same
    {
    	enum { value = 0 };
    	typedef __false_type type;
    };

  	template<typename T>
    struct are_const_same<T, T>
    {
    	enum { value = 1 };
    	typedef __true_type type;
    };
	
	template<typename T>
    struct are_const_same<const T, T>
    {
    	enum { value = 1 };
    	typedef __true_type type;
    };
	
	template<typename T>
    struct are_const_same<T, const T>
    {
    	enum { value = 1 };
    	typedef __true_type type;
    };

}
#endif
