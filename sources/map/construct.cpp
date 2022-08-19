/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:18:58 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/17 17:47:22 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

template<typename K, typename T>
void	showMap(NSP::map<K, T> &map)
{
	typename NSP::map<K, T>::iterator	it = map.begin();

	while (it != map.end())
	{
		std::cout << "\t" << (*it).first << "\t:\t" << (*it).second << std::endl;
		it++;
	}
}

static void	mapConstructionInt(void)
{
	NSP::pair<int, int>	pair1(150, 0);
	NSP::pair<int, int>	pair2(2, 1);
	NSP::pair<int, int>	pair3(100, 2);
	NSP::pair<int, int> pair4(1, 3);

	// default constructor
	NSP::map<int, int>	map;
	printTitle("map construction <int, int>", BORANGE);
	printSubtitle("default constructor", ORANGE);

	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);
	showMap(map);

	// copy constructor
	printSubtitle("copy constructor", ORANGE);
	NSP::map<int, int>	mapCopy(map);
	map.clear();
	std::cout << "original map cleared" << std::endl << std::endl;
	std::cout << "copy :" << std::endl;
	showMap(mapCopy);
	std::cout << std::endl << "original :" << std::endl;
	showMap(map);

	// iterator constructor
	printSubtitle("iterator constructor", ORANGE);
	std::vector< NSP::pair<int, int> >	v;
	v.push_back(pair1);
	v.push_back(pair2);
	v.push_back(pair3);
	v.push_back(pair4);

	map.insert(v.rbegin(), v.rend());
	showMap(map);
}

static void	mapConstructionString(void)
{
	NSP::pair<int, std::string>	pair1(150, "string1");
	NSP::pair<int, std::string>	pair2(2, "string2");
	NSP::pair<int, std::string>	pair3(100, "string3");
	NSP::pair<int, std::string> pair4(1, "string4");

	// default constructor
	NSP::map<int, std::string>	map;
	printTitle("map construction <int, string>", BORANGE);
	printSubtitle("default constructor", ORANGE);

	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);
	showMap(map);

	// copy constructor
	printSubtitle("copy constructor", ORANGE);
	NSP::map<int, std::string>	mapCopy(map);
	map.clear();
	std::cout << "original map cleared" << std::endl << std::endl;
	std::cout << "copy :" << std::endl;
	showMap(mapCopy);
	std::cout << std::endl << "original :" << std::endl;
	showMap(map);

	// iterator constructor
	printSubtitle("iterator constructor", ORANGE);
	std::vector< NSP::pair<int, std::string> >	v;
	v.push_back(pair1);
	v.push_back(pair2);
	v.push_back(pair3);
	v.push_back(pair4);

	map.insert(v.rbegin(), v.rend());
	showMap(map);
}

void	mapConstruction(void)
{
	mapConstructionString();
	mapConstructionInt();
}
