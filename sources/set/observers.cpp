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

#include "testMap.hpp"

void	mapObservers(void)
{
	printTitle("map observers", BORANGE);
	printSubtitle("key_comp()", ORANGE);
	NSP::map<char,int> mapK;
  	NSP::map<char,int>::key_compare compare = mapK.key_comp();
	mapK['a']=100;
	mapK['b']=200;
	mapK['c']=300;
	printMap(mapK);
	
	std::cout << "map contains:" << std::endl;
	char highest = mapK.rbegin()->first;
	NSP::map<char,int>::iterator it = mapK.begin();
	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while (compare((*it++).first, highest));
	std::cout << std::endl;

	printSubtitle("value_comp()", ORANGE);
	NSP::map<char,int> mapV;

	mapV['x']=1001;
	mapV['y']=2002;
	mapV['z']=3003;

	std::cout << "map contains:\n";

	NSP::pair<char,int> high = *mapV.rbegin();

	NSP::map<char,int>::iterator itV = mapV.begin();
	do {
		std::cout << itV->first << " => " << itV->second << '\n';
	} while ( mapV.value_comp()(*itV++, high) );
}