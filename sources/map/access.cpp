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

void	mapElementAccess(void)
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

	// operator[]
	printSubtitle("access with operator[]", ORANGE);
	std::cout << "map[1] = " << map[1] << std::endl;
	std::cout << "map[2] = " << map[2] << std::endl;
	std::cout << "map[100] = " << map[100] << std::endl;
	std::cout << "map[150] = " << map[150] << std::endl;
	std::cout << "map[0] = " << map[0] << std::endl;
	std::cout << std::endl;
	showMap(map);
	std::cout << "/!\\ map[0] should be created" << std::endl;

	printSubtitle("assign with operator[]", ORANGE);
	map[150] = -4;
	map[2] = -1;
	map[100] = -2;
	map[1] = -3;
	showMap(map);
}
