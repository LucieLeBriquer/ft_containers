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

#include "testSet.hpp"

void	setFind(void)
{
	printTitle("set find and count", BORANGE);
	
	printSubtitle("find()", ORANGE);
	NSP::set<char> setF;
  	NSP::set<char>::iterator itF;
	setF.insert('a'); 
	setF.insert('b'); 
	setF.insert('c'); 
	setF.insert('d');
	printSet(setF);

	itF = setF.find('b');
	if (itF != setF.end())
		setF.erase(itF);
	std::cout << "erase(find('b'))" << std::endl;

	std::cout << "elements in setF:" << std::endl;
	std::cout << "find(a) => " << *(setF.find('a')) << std::endl;;
	std::cout << "find(c) => " << *(setF.find('c')) << std::endl;
	std::cout << "find(d) => " << *(setF.find('d')) << std::endl;


	printSubtitle("count()", ORANGE);
	NSP::set<char> setC;
  	char			c;

	setC.insert('a');
	setC.insert('c');
	setC.insert('f');
	printSet(setC);

  	for (c = 'a'; c < 'h'; c++)
  	{
  	  	std::cout << c;
  	  	if (setC.count(c) > 0)
  			std::cout << " is an element of set.\n";
  	  	else 
  	  		std::cout << " is not an element of set.\n";
  	}
}
