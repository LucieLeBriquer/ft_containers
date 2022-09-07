/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:58:23 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 13:58:36 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testVector.hpp"

void	vectorIterators(void)
{
	printTitle("iterators", BORANGE);

	std::list<int>		lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(3 * i + 1);
	NSP::vector<int>	v(lst.begin(), lst.end());

	NSP::vector<int>::iterator			it = v.begin();
	std::cout << "(*begin()) = " << *it << std::endl;
	std::cout << "dist between end() and begin() = " << (v.end() - v.begin()) << std::endl;
	std::cout << "vector size = " << v.size() << std::endl;
	std::cout << std::endl;
	NSP::vector<int>::reverse_iterator	rit = v.rbegin();
	std::cout << "(*rbegin()) = " << *rit << std::endl;
	std::cout << "dist between rend() and rbegin() = " << (v.rend() - v.rbegin()) << std::endl;
	std::cout << "vector size = " << v.size() << std::endl;
}