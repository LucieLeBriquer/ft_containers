/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:51:22 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/24 11:09:00 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testSet.hpp"

void	setObservers(void)
{
	printTitle("set observers", BORANGE);
	printSubtitle("key_comp()", ORANGE);
	NSP::set<char> 				setK;
  	NSP::set<char>::key_compare	compare = setK.key_comp();
	setK.insert('a');
	setK.insert('b');
	setK.insert('c');
	printSet(setK);
	
	std::cout << "set contains:" << std::endl;
	char highest = *(setK.rbegin());
	NSP::set<char>::iterator it = setK.begin();
	do {
		std::cout << *it << std::endl;
	} while (compare((*it++), highest));
	std::cout << std::endl;

	printSubtitle("value_comp()", ORANGE);
	NSP::set<char> setV;

	setV.insert('x');
	setV.insert('y');
	setV.insert('z');

	std::cout << "set contains:\n";

	char high = *setV.rbegin();

	NSP::set<char>::iterator itV = setV.begin();
	do {
		std::cout << *itV << std::endl;
	} while ( setV.value_comp()(*itV++, high) );
}
