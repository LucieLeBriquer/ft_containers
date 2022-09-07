/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:19:08 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 13:19:39 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testVector.hpp"

static void	vectorAssign(void)
{
	printTitle("vector assign", BORANGE);
	NSP::vector<std::string>	vBase(10, "a");
	NSP::vector<std::string>	v1(vBase);

	printSubtitle("vector assign from iterator", ORANGE);
	v1.assign(vBase.rbegin(), vBase.rend() - 3);
	printVector(v1);
	printSubtitle("vector assign(n, val)", ORANGE);
	v1.assign(15, "b");
	printVector(v1);
}

static void	vectorInsertion(void)
{
	printTitle("vector insert", BORANGE);
	NSP::vector<int>	vBase(10, 0);
	NSP::vector<int>	v1(vBase);
	NSP::vector<int>	v2(vBase);
	NSP::vector<int>	v3(vBase);

	printSubtitle("vector insert val at begin() + 2", ORANGE);
	std::cout << YELLOW << "before insertion" << END << std::endl;
	printVector(v1);
	v1.insert(v1.begin() + 2, 4);
	std::cout << std::endl << YELLOW << "after insertion" << END << std::endl;
	printVector(v1);

	printSubtitle("vector insert 3 * val at begin() + 2", ORANGE);
	std::cout << YELLOW << "before insertion" << END << std::endl;
	printVector(v2);
	v2.insert(v2.begin() + 2, 3, 4);
	std::cout << std::endl << YELLOW << "after insertion" << END << std::endl;
	printVector(v2);

	printSubtitle("vector insert range at begin() + 4", ORANGE);
	std::list<int>	l;
	for (int i = 0; i < 6; i++)
		l.push_back(i);
	std::cout << YELLOW << "before insertion" << END << std::endl;
	printVector(v3);
	v3.insert(v3.begin() + 4, l.begin(), l.end());
	std::cout << std::endl << YELLOW << "after insertion" << END << std::endl;
	printVector(v3);
}

void	vectorInsert(void)
{
	vectorAssign();
	vectorInsertion();
}
