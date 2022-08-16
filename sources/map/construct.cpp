/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:18:58 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/16 17:40:31 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

void	showMap(NSP::map<int, std::string> &map)
{
	NSP::map<int, std::string>::iterator	it = map.begin();

	while (it != map.end())
	{
		std::cout << "\t" << (*it).first << " - " << (*it).second << std::endl;
		it++;
	}
}

void	testMapConstruction(void)
{
	NSP::pair<int, std::string>	pair1(150, "string1");
	NSP::pair<int, std::string>	pair2(2, "string2");
	NSP::pair<int, std::string>	pair3(100, "string3");
	NSP::pair<int, std::string> pair4(1, "string4");

	NSP::map<int, std::string>	map;
	printTitle("map construction", BORANGE);
	printSubtitle("default constructor", ORANGE);

	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);
	showMap(map);

	printSubtitle("copy constructor", ORANGE);
	NSP::map<int, std::string>	mapCopy(map);
	map.clear();
	std::cout << "original map cleared" << std::endl << std::endl;
	std::cout << "copy :" << std::endl;
	showMap(mapCopy);
	std::cout << std::endl << "original :" << std::endl;
	showMap(map);
}