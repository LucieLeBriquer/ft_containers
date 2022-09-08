/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:38:03 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/08 12:26:48 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testSet.hpp"

void	setBound(void)
{
	printTitle("set bound functions", BORANGE);
	printSubtitle("upper_bound(), lower_bound()", ORANGE);
	NSP::set<char>				setB;
  	NSP::set<char>::iterator	itlow,itlow2,itup,itup2;

	setB.insert('a');
	setB.insert('b');
	setB.insert('c');
	setB.insert('d');
	printSet(setB);

 	itlow = setB.lower_bound('b');
	itlow2 = setB.lower_bound('c');
  	itup = setB.upper_bound('a');
	itup2 = setB.upper_bound('b');

	std::cout << "lower_bound(b)" << std::endl;
	printValue(itlow);
	std::cout << std::endl;
	std::cout << "upper_bound(b)" << std::endl;
	printValue(itup2);
	std::cout << std::endl;
	std::cout << "lower_bound(c)" << std::endl;
	printValue(itlow2);
	std::cout << std::endl;
	std::cout << "upper_bound(a)" << std::endl;
	printValue(itup);
	std::cout << std::endl;
}
