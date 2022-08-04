/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/22 16:01:11 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "map.hpp"
#include "simple.hpp"
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

	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);


	NSP::map<int, std::string>::const_iterator		itEnd(map.end());
	it = map.begin();

	while (it != itEnd)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
		it++;
	}
}
