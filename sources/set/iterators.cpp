/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:03:17 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/08 12:37:24 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testSet.hpp"

void    setIterators(void)
{
	printTitle("set iterator", BORANGE);
	printSubtitle("construction", ORANGE);
    NSP::set<int>					set;
    NSP::set<int>::iterator		    it = set.begin();
    NSP::set<int>::const_iterator	cit = set.begin();

    NSP::set<int>::reverse_iterator		    rit(it);
    NSP::set<int>::const_reverse_iterator	crit(rit);
    NSP::set<int>::const_reverse_iterator	crit2(it);
    NSP::set<int>::const_reverse_iterator	crit3(cit);
	
	(void)crit;
	(void)crit2;
	(void)cit;
	(void)crit3;

	//shouldn't compile
    //NSP::set<int>::reverse_iterator	rit2(crit);
    //NSP::set<int>::iterator 			it2(rit);
    //NSP::set<int>::const_iterator 	cit2(crit);

    std::cout << "All went well" << std::endl;
	
	
	printSubtitle("reverse iterators", ORANGE);
    std::list<char>	lst;

    for (unsigned int i = 0; i < 10; ++i)
        lst.push_back('l' + i);

    NSP::set<char>					    set2(lst.begin(), lst.end());
    NSP::set<char>::iterator			normalIt = set2.begin();
    NSP::set<char>::reverse_iterator    rit2(normalIt);
	NSP::set<char>::reverse_iterator	rite2;

    printSet(set2);

	std::cout << YELLOW << "getting base() iterator from base iterator" << END << std::endl;
    std::cout << (normalIt == rit2.base() ? "true" : "false") << "  (should be true)" << std::endl;
    std::cout << (normalIt == (--(--(--(rit2)))).base() ? "true" : "false") << " (should be false)"  << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "increments on base() iterator and directly on rit" << END << std::endl;
	++(rit2.base());
    printValue(rit2);
    --rit2;
    printValue(rit2);
    printValue(rit2.base());
	std::cout << std::endl;

    std::cout << YELLOW << "from rbegin() to rend()" << END << std::endl;
    rit2 = set2.rbegin();
	rite2 = set2.rend();
    while (rit2 != rite2)
		printValue(rit2++);
	
	std::cout << std::endl;
    std::cout << YELLOW << "from end() to begin()" << END << std::endl;
	printSetRev(set2);
}