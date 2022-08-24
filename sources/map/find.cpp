/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:22:24 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/24 11:28:31 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

void	mapFind(void)
{
	printTitle("map find and count", BORANGE);
	
	printSubtitle("find()", ORANGE);
	NSP::map<char,int> mapF;
  	NSP::map<char,int>::iterator itF; 
	mapF['a']=50;
	mapF['b']=100;
	mapF['c']=150;
	mapF['d']=200;
	printMap(mapF);

	itF = mapF.find('b');
	if (itF != mapF.end())
		mapF.erase(itF);
	std::cout << "erase(find('b'))" << std::endl;

	std::cout << "elements in mapF:" << std::endl;
	std::cout << "a => " << mapF.find('a')->second << std::endl;;
	std::cout << "c => " << mapF.find('c')->second << std::endl;
	std::cout << "d => " << mapF.find('d')->second << std::endl;


	printSubtitle("count()", ORANGE);
	NSP::map<char,int> mapC;
  	char				c;

  	mapC['a']=101;
  	mapC['c']=202;
  	mapC['f']=303;
	printMap(mapC);

  	for (c = 'a'; c < 'h'; c++)
  	{
  	  	std::cout << c;
  	  	if (mapC.count(c) > 0)
  			std::cout << " is an element of map.\n";
  	  	else 
  	  		std::cout << " is not an element of map.\n";
  	}
}
