/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:51:16 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/19 10:52:29 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

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

template <typename T1, typename T2>
void    printReverse(NSP::map<T1, T2> &mp)
{
    typename NSP::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

    std::cout << "printReverse:" << std::endl;
    while (it != ite) {
        it--;
        std::cout << "-> " << printPair(it, false) << std::endl;
    }
    std::cout << "_______________________________________________" << std::endl;
}

#include <list>
#define T1 int
#define T2 int
typedef _pair<T1, T2> T3;

void     fail(void)
{
	std::list<T3> lst;
    unsigned int lst_size = 7;
    for (unsigned int i = 0; i < lst_size; ++i)
        lst.push_back(T3(lst_size - i, i));

    NSP::map<T1, T2> mp(lst.begin(), lst.end());
    NSP::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
	printSize(mp);

	//std::cout << --(--ite)->second << std::endl;
	std::cout <<  "--(--ite) value=" <<  (--(--ite))->second << std::endl;

    NSP::map<T1, T2> mp_range(it, ++(++it));
	printSize(mp_range);
    /*for (int i = 0; it != ite; ++it)
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
    printSize(mp_copy);*/
	
}
void	elementAccess(void)
{
	NSP::pair<int, int>	pair1(150, 0);
	NSP::pair<int, int>	pair2(2, 1);
	NSP::pair<int, int>	pair3(100, 2);
	NSP::pair<int, int> pair4(1, 3);

	NSP::map<int, int>	map;
	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);

	printTitle("map element access", BORANGE);

	// show map with iterator
	printSubtitle("access with iterator", ORANGE);
	NSP::map<int, int>::iterator		it = map.begin();
	NSP::map<int, int>::const_iterator	ite = map.end();
	while (it != ite)
	{
		std::cout << it->first << " : " << it->second << std::endl;
		it++;
	}

	printSubtitle("access with reverse iterator", ORANGE);
	NSP::map<int, int>::reverse_iterator		rit = map.rbegin();
	NSP::map<int, int>::const_reverse_iterator	rite = map.rend();
	while (rit != rite)
	{
		std::cout << rit->first << " : " << rit->second << std::endl;
		rit++;
	}
}