/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/05 12:32:08 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "map.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define ORANGE "\x1B[34m"
#define PURPLE "\x1B[35m"
#define BLUE "\x1B[36m"
#define BOLD "\x1B[1m"
#define END "\x1B[0m"
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
	NSP::map<int, std::string>	map;
	NSP::pair<int, std::string>	pair1(150, "lucie");
	NSP::pair<int, std::string>	pair2(2, "jonathan");
	NSP::pair<int, std::string>	pair3(100, "lise");
	NSP::pair<int, std::string> pair4(1, "soji");
	NSP::map<int, std::string>::iterator			it;
	NSP::map<int, std::string>::reverse_iterator	rit;
	std::map<int, std::string>::reverse_iterator	rit2;

	map.insert(pair3);
	map.insert(pair2);
	map.insert(pair1);
	map.insert(pair4);
	//map.print();
	it = map.begin();
	int i = 0;
	while (it != map.end())
	{
		std::cout << "[" << i << "] " << it->first << " : " << it->second << std::endl;
		it++;
		i++;
	}
	std::cout << std::endl;
	rit = map.rbegin();
	i = 0;
	while (rit != map.rend())
	{
		std::cout << "[" << i << "] " << rit->first << " : " << rit->second << std::endl;
		rit++;
		i++;
	}
}