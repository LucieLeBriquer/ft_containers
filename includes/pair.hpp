/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:49:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/27 16:07:10 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
    struct pair
    {
		public:
	
			typedef T1	first_type;
			typedef T2	second_type;

			T1	first;
			T2	second;

			pair() : first(), second() { }

			template<class U, class V>
			pair(const pair<U,V> &p) : first(p.first), second(p.second) { }

			pair(const T1 &a, const T2 &b) : first(a), second(b) { }
			
			pair& operator=(const pair &p)
			{
				if (this != &p)
				{
					first = p.first;
					second = p.second;
				}
				return (*this);
			}
	};
	
	template <class T1, class T2>
	bool operator==(const pair<T1,T2> &p1, const pair<T1,T2> &p2)
	{
		return (p1.first == p2.first && p1.second == p2.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2> &p1, const pair<T1,T2> &p2)
	{
		return (!(p1 == p2));
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2> &p1, const pair<T1,T2> &p2)
	{
		return (p1.first < p2.first || (!(p2.first < p1.first) && p1.second < p2.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2> &p1, const pair<T1,T2> &p2)
	{
		return (!(p2 < p1));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2> &p1, const pair<T1,T2> &p2)
	{
		return (p2 < p1);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2> &p1, const pair<T1,T2> &p2)
	{
		return (!(p1 < p2));
	}

	template <class T1,class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	}
	
}

#endif
