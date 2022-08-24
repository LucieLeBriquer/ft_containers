/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:03:17 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/24 13:09:00 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"
#include <list>

void     mapIterators(void)
{
	printTitle("map iterator", BORANGE);
	printSubtitle("construction", ORANGE);
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

    std::cout << "All went well" << std::endl;
	
	
	printSubtitle("reverse iterators", ORANGE);
	typedef NSP::pair<const char, int> Pair;

    std::list<Pair>	lst;

    for (unsigned int i = 0; i < 10; ++i)
        lst.push_back(Pair('l' + i, 2 * i));

    NSP::map<const char, int>					map2(lst.begin(), lst.end());
    NSP::map<const char, int>::iterator			normalIt = map2.begin();
    NSP::map<const char, int>::reverse_iterator rit2(normalIt);
	NSP::map<const char, int>::reverse_iterator	rite2;

    printMap(map2);

	std::cout << YELLOW << "getting base() iterator from base iterator" << END << std::endl;
    std::cout << (normalIt == rit2.base() ? "true" : "false") << "  (should be true)" << std::endl;
    std::cout << (normalIt == (--(--(--(rit2)))).base() ? "true" : "false") << " (should be false)"  << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "increments on base() iterator and directly on rit" << END << std::endl;
	++(rit2.base());
    printPair(rit2);
    --rit2;
    printPair(rit2);
    printPair(rit2.base());
	std::cout << std::endl;

    std::cout << YELLOW << "from rbegin() to rend()" << END << std::endl;
    rit2 = map2.rbegin();
	rite2 = map2.rend();
    while (rit2 != rite2)
		printPair(rit2++);
	
	std::cout << std::endl;
    std::cout << YELLOW << "from end() to begin()" << END << std::endl;
	printMapRev(map2);
	
	NSP::map<char, int>::iterator itt;
    NSP::map<const char, int>::const_iterator itte;

	std::cout << "let's go segfault" << std::endl;
    std::cout << (itt != itte) << std::endl;
}