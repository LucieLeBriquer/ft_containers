/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:34:27 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 13:40:51 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testVector.hpp"

void	vectorErase(void)
{
	printTitle("vector erase", BORANGE);
	std::list<std::string>	l;
	for (int i = 0; i < 10; i++)
		l.push_back(std::string(3, 'a' + i));
	
	NSP::vector<std::string>	v(l.begin(), l.end());

	printSubtitle("erase(begin(), begin() + 3)", ORANGE);
	std::cout << YELLOW << "before erase" << END << std::endl;
	printVector(v);
	v.erase(v.begin(), v.begin() + 3);
	std::cout << std::endl << YELLOW << "after erase" << END << std::endl;
	printVector(v);

	printSubtitle("erase(end() - 1)", ORANGE);
	std::cout << YELLOW << "before erase" << END << std::endl;
	printVector(v);
	v.erase(v.end() - 1);
	std::cout << std::endl << YELLOW << "after erase" << END << std::endl;
	printVector(v);
}