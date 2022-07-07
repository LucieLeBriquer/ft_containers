/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/07 18:31:54 by lle-briq         ###   ########.fr       */
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

	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);


	NSP::map<int, std::string>	map2(map);
	NSP::map<int, std::string>	map3;

	map3 = map;
	map3 = map2;

	/* map.print();
	map2.print();
	map3.print(); */
	std::cout << "map is filled" << std::endl;
	
	it = map.begin();
	int i = 0;
	while (it != map.end())
	{
		std::cout << "[" << i << "] " << it->first << " : " << it->second << std::endl;
		it++;
		i++;
	}
	std::cout << std::endl;
	
	/* rit = map.rbegin();
	i = 0;
	while (rit != map.rend())
	{
		std::cout << "[" << i << "] " << rit->first << " : " << rit->second << std::endl;
		rit++;
		i++;
	}
	std::cout << std::endl;

	NSP::map<int, std::string>	copy(map.begin(), map.end());
	it = copy.begin();
	while (it != copy.end())
	{
		std::cout << it->first << " : " << it->second << std::endl;
		it++;
	} */
}