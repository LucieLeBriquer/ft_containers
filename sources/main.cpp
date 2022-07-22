/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/21 19:19:04 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "map.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#ifdef USESTL
# define NSP std
# define ISFT 0
#else
# define NSP ft
# define ISFT 1
#endif
#define SIZE 60


void	printMap(NSP::map<int, std::string>	map, std::string prefix)
{
	NSP::map<int, std::string>::iterator	it;

	std::cout << YELLOW << ">> " << prefix << END << std::endl;
	it = map.begin();
	while (it != map.end())
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
		it++;
	}
	std::cout << std::endl;
}

int	main(void)
{
	NSP::pair<int, std::string>	pair1(150, "lucie");
	NSP::pair<int, std::string>	pair2(2, "jonathan");
	NSP::pair<int, std::string>	pair3(100, "lise");
	NSP::pair<int, std::string> pair4(1, "soji");

	NSP::map<int, std::string>	map;
	NSP::map<int, std::string>::iterator			it;
	NSP::map<int, std::string>::iterator			itEnd;
	NSP::map<int, std::string>::reverse_iterator	rit;

	std::cout << "map is empty ? " << map.empty() << std::endl;
	std::cout << "map size = " << map.size() << std::endl;
	std::cout << "map max_size = " << map.max_size() << std::endl;

	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);
	std::cout << map[100] << std::endl;
	std::cout << map[10] << std::endl;
	std::cout << "map is empty ? " << map.empty() << std::endl;
	std::cout << "map size = " << map.size() << std::endl;
	std::cout << "map max_size = " << map.max_size() << std::endl;

	NSP::map<int, std::string>	map2(map);
	NSP::map<int, std::string>	map3;

	map3.insert(map2.begin(), map2.end());

	printMap(map, "map");
	printMap(map2, "map2");
	printMap(map3, "map3");

	it = map.begin();
	it++;
	map.erase(it);
	std::cout << map.erase(1) << std::endl;
	std::cout << map.erase(1) << std::endl;
	std::cout << map.erase(150) << std::endl;
	std::cout << map.erase(123) << std::endl;
	std::string	str = "0123456789";
	
	for (int i = 0; i < 10; i++)
		map[i] = str.substr(i, 1);

	printMap(map, "map");
	printMap(map2, "map2");
	printMap(map3, "map3");
}
