/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:38:03 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 18:40:37 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

void	mapBound(void)
{
	printTitle("map bound functions", BORANGE);
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
  	itup = mapB.upper_bound('a');
	itup2 = mapB.upper_bound('b');

	std::cout << "lower_bound(b)" << std::endl;
	printPairMap(itlow);
	std::cout << std::endl;
	std::cout << "upper_bound(b)" << std::endl;
	printPairMap(itup2);
	std::cout << std::endl;
	std::cout << "lower_bound(c)" << std::endl;
	printPairMap(itlow2);
	std::cout << std::endl;
	std::cout << "upper_bound(a)" << std::endl;
	printPairMap(itup);
	std::cout << std::endl;
}
