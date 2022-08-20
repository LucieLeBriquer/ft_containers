/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:03:17 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/20 15:32:19 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"
# include <list>

#define _pair NSP::pair

template <typename T>
std::string printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
    o << "key: " << iterator->first << " | value: " << iterator->second;
    if (nl)
        o << std::endl;
    return ("");
}

template <typename T_MAP>
void    printSize(T_MAP const &mp, bool print_content = 1)
{
    std::cout << "size: " << mp.size() << std::endl;
    std::cout << "max_size: " << mp.max_size() << std::endl;
    if (print_content)
    {
        typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
        for (; it != ite; ++it)
            std::cout << "- " << printPair(it, false) << std::endl;
    }
    std::cout << "###############################################" << std::endl;
}

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

void	fail(void)
{
    std::list<T3> lst;
    unsigned int lst_size = 7;
    for (unsigned int i = 0; i < lst_size; ++i)
        lst.push_back(T3(lst_size - i, i));

    NSP::map<T1, T2> mp(lst.begin(), lst.end());
    NSP::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

    NSP::map<T1, T2> mp_range(it, --(--ite));
    for (int i = 0; it != ite; ++it)
        it->second = ++i * 5;

    it = mp.begin(); ite = --(--mp.end());
    NSP::map<T1, T2> mp_copy(mp);
    for (int i = 0; it != ite; ++it)
        it->second = ++i * 7;

    std::cout << "\t-- PART ONE --" << std::endl;
    printSize(mp);
    printSize(mp_range);
    printSize(mp_copy);

    mp = mp_copy;
    mp_copy = mp_range;
    mp_range.clear();

    std::cout << "\t-- PART TWO --" << std::endl;
    printSize(mp);
    printSize(mp_range);
    printSize(mp_copy);
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


    NSP::map<int, int>						map2;
    NSP::map<int, int>::iterator			ite = map2.end();
	(void)ite;
	(void)crit;
	(void)crit2;
	(void)cit;
	(void)crit3;
	//shouldn't compile
    //NSP::map<int, int>::reverse_iterator	rit2(crit);
	//(void)rit2;
    //NSP::map<int, int>::reverse_iterator 	rit3(cit);
    //NSP::map<int, int>::iterator 			it2(rit);
    //NSP::map<int, int>::const_iterator 	cit2(crit);

    std::cout << "OK" << std::endl;
	fail();
}