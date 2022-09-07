/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:51:48 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 13:52:49 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testVector.hpp"

void	vectorAccess(void)
{
	printTitle("vector access", BORANGE);
	std::list<std::string>	l;
	for (int i = 0; i < 10; i++)
		l.push_back(std::string(3, 'a' + i));
	
	NSP::vector<std::string>	v(l.begin(), l.end());

	printSubtitle("operator[]", ORANGE);
	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	
	printSubtitle("assign with operator[]", ORANGE);
	for (int i = 0; i < 10; i++)
		v[i] = v[i] + "h";
	printVector(v);

	printSubtitle("at(4)", ORANGE);
	std::cout << v.at(4) << std::endl;

	printSubtitle("front()", ORANGE);
	std::cout << v.front() << std::endl;

	printSubtitle("back()", ORANGE);
	std::cout << v.back() << std::endl;
}