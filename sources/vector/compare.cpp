/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:03:28 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 14:04:06 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testVector.hpp"

void	vectorCompare(void)
{
	printTitle("vector compare", BORANGE);

	std::list<int>		lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(3 * i + 1);
	NSP::vector<int>	v1(lst.begin(), lst.end());
	NSP::vector<int>	v2(lst.begin(), lst.end());
	
	std::cout << "(v1)" << std::endl;
	printVector(v1);
	std::cout << std::endl;
	std::cout << "(v2)" << std::endl;
	printVector(v2);
	std::cout << std::endl << "== ? " << (v1 == v2) << std::endl;
	std::cout << "<= ? " << (v1 <= v2) << std::endl;
	std::cout << ">= ? " << (v1 >= v2) << std::endl;
	std::cout << " > ? " << (v1 > v2) << std::endl;
	std::cout << " < ? " << (v1 < v2) << std::endl;
	std::cout << "!= ? " << (v1 != v2) << std::endl;
	std::cout << std::endl;

	v1.assign(lst.begin(), lst.end());
	v2.assign(lst.rbegin(), lst.rend());
	
	std::cout << "(v1)" << std::endl;
	printVector(v1);
	std::cout << std::endl;
	std::cout << "(v2)" << std::endl;
	printVector(v2);
	std::cout << std::endl << "== ? " << (v1 == v2) << std::endl;
	std::cout << "<= ? " << (v1 <= v2) << std::endl;
	std::cout << ">= ? " << (v1 >= v2) << std::endl;
	std::cout << " > ? " << (v1 > v2) << std::endl;
	std::cout << " < ? " << (v1 < v2) << std::endl;
	std::cout << "!= ? " << (v1 != v2) << std::endl;
}