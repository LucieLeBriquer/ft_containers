/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:24:26 by lle-briq          #+#    #+#             */
/*   Updated: 2022/04/02 16:24:26 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	template<bool, typename>
	struct enable_if 
	{ };

	template<typename T>
	struct enable_if<true, T>
	{ typedef T type; };

	// compare type equality

  	template<typename T1, typename T2>
    struct are_same
    {
      enum { value = 0 };
      typedef false_type type;
    };

  	template<typename T>
    struct are_same<T, T>
    {
      enum { value = 1 };
      typedef true_type type;
    };

}
#endif
