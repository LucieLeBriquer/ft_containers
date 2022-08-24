/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:38:03 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/24 11:38:59 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

void	mapBound(void)
{
	printTitle("map bound/range functions", BORANGE);
	printSubtitle("upper_bound(), lower_bound()", ORANGE);
	NSP::map<char,int>				mapB;
  	NSP::map<char,int>::iterator	itlow,itlow2,itup,itup2;

	mapB['a'] = 20;
	mapB['b'] = 40;
	mapB['d'] = 80;
	mapB['e'] = 100;
	printMap(mapB);

 	itlow = mapB.lower_bound('b');
	itlow2 = mapB.lower_bound('c');
  	itup = mapB.upper_bound('d');
	itup2 = mapB.upper_bound('b');

	std::cout << "lower_bound(b)" << std::endl;
	printPair(itlow);
	std::cout << std::endl;
	std::cout << "upper_bound(b)" << std::endl;
	printPair(itup2);
	std::cout << std::endl;
	std::cout << "lower_bound(c)" << std::endl;
	printPair(itlow2);
	std::cout << std::endl;
	std::cout << "upper_bound(d)" << std::endl;
	printPair(itup);
	std::cout << std::endl;

	printSubtitle("equal_range()", ORANGE);
}
