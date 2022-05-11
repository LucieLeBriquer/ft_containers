/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:49:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/11 12:00:03 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
    struct pair
    {
    	typedef T1	first_type;
    	typedef T2	second_type;

      	T1	first;
    	T2	second;

    	pair() : first(), second() { }

		template<class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) { }

    	pair(const T1& a, const T2& b) : first(a), second(b) { }
		
		pair& operator=(const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};
}

#endif
