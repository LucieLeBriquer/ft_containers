/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:03:17 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/22 18:23:41 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"
#include <list>
#define T1 char
#define T2 int
typedef NSP::pair<const T1, T2> T3;

template <typename T>
T   inc(T it, int n)
{
    while (n-- > 0)
        ++it;
    return (it);
}

template <typename T>
T   dec(T it, int n)
{
    while (n-- > 0)
        --it;
    return (it);
}


template <typename T, typename U>
void    printReverse(NSP::map<T, U> &mp)
{
    typename NSP::map<T, U>::iterator it = mp.end(), ite = mp.begin();

    std::cout << "printReverse:" << std::endl;
    while (it != ite) {
        it--;
        std::cout << "-> ";
		printPair(it);
    }
    std::cout << "_______________________________________________" << std::endl;
}

void	failing(void)
{
    std::list<T3> lst;
    unsigned int lst_size = 5;
    for (unsigned int i = 0; i < lst_size; ++i)
        lst.push_back(T3('a' + i, (i + 1) * 7));

    NSP::map<T1, T2> mp(lst.begin(), lst.end());
    NSP::map<T1, T2>::iterator it_ = mp.begin();
    NSP::map<T1, T2>::reverse_iterator it(it_), ite;
    printMap(mp);

    std::cout << (it_ == it.base()) << std::endl;
    std::cout << (it_ == dec(it, 3).base()) << std::endl;
	
    printPair(inc(it.base(), 1));

    std::cout << "TEST OFFSET" << std::endl;
    --it;
    printPair(it);
    printPair(it.base());

    it = mp.rbegin(); ite = mp.rend();
    while (it != ite)
	{
        std::cout << "[rev] ";
		printPair(it++);
	}
    printReverse(mp);
}

void     mapIterators(void)
{
    NSP::map<int, int>					map;
    NSP::map<int, int>::iterator		it = map.begin();
    NSP::map<int, int>::const_iterator	cit = map.begin();

    NSP::map<int, int>::reverse_iterator		rit(it);
    NSP::map<int, int>::const_reverse_iterator	crit(rit);
    NSP::map<int, int>::const_reverse_iterator	crit2(it);
    NSP::map<int, int>::const_reverse_iterator	crit3(cit);
	
	(void)crit;
	(void)crit2;
	(void)cit;
	(void)crit3;

	//shouldn't compile
    //NSP::map<int, int>::reverse_iterator	rit2(crit);
    //NSP::map<int, int>::reverse_iterator 	rit3(cit);
    //NSP::map<int, int>::iterator 			it2(rit);
    //NSP::map<int, int>::const_iterator 	cit2(crit);

	printTitle("map iterator", BORANGE);
    std::cout << std::endl << "All went well" << std::endl;
	failing();
}