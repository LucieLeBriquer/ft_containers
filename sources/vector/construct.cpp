/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:20:06 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 13:17:29 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testVector.hpp"

static void	simple(void)
{
	NSP::vector<int>	v;

	printSubtitle("default constructor and push back", ORANGE);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	printVector(v);
}

static void	fillConstruct(void)
{
	printSubtitle("fill constructor", ORANGE);
	NSP::vector<int>	v(10, 5);

	printVector(v);
}

static void	iteratorConstruct(void)
{
	printSubtitle("iterator constructor from list", ORANGE);
	std::list<int>		lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(3 * i + 1);
	NSP::vector<int>	v(lst.begin(), lst.end());
	NSP::vector<int>	vR(lst.rbegin(), lst.rend());

	std::cout << YELLOW << "from lst.begin() to lst.end()" << END << std::endl;
	printVector(v);
	std::cout << std::endl;
	std::cout << YELLOW << "from lst.rbegin() to lst.rend()" << END << std::endl;
	printVector(vR);
}

static void	copyConstruct(void)
{
	printSubtitle("copy constructor", ORANGE);
	std::list<int>		lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(3 * i + 1);
	NSP::vector<int>	v(lst.begin(), lst.end());
	NSP::vector<int>	vCopy(v);

	std::cout << YELLOW << "original" << END << std::endl;
	printVector(v);
	std::cout << std::endl << YELLOW << "copy" << END << std::endl;
	printVector(vCopy);
	std::cout << std::endl << YELLOW << "after clearing original, copy :" << END << std::endl;
	v.clear();
	printVector(vCopy);
}

void	vectorConstruction(void)
{
	printTitle("vector construction", BORANGE);
	simple();
	fillConstruct();
	iteratorConstruct();
	copyConstruct();
}
