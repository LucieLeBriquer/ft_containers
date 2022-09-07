/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:05:49 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 15:05:49 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testStack.hpp"

template<typename Container>
static void	compareFunc(std::string name)
{
	printTitle("stacks with " + name + " container", BORANGE);
	Container					v1(10,4);
	Container					v2(3,2);
	NSP::stack<int, Container>	s1(v1);
	NSP::stack<int, Container>	s2(v2);

	printSubtitle("initialized with v1(10,4) and v2(3,2)", ORANGE);
	std::cout << "s1 == s2 ? " << (s1 == s2) << std::endl;
	std::cout << "s1 != s2 ? " << (s1 != s2) << std::endl;
	std::cout << "s1 <= s2 ? " << (s1 <= s2) << std::endl;
	std::cout << "s1 >= s2 ? " << (s1 >= s2) << std::endl;
	std::cout << " s1 < s2 ? " << (s1 > s2) << std::endl;
	std::cout << " s1 > s2 ? " << (s1 > s2) << std::endl;

	s1 = s2;
	printSubtitle("after s1 = s2 :", ORANGE);
	std::cout << "s1 == s2 ? " << (s1 == s2) << std::endl;
	std::cout << "s1 != s2 ? " << (s1 != s2) << std::endl;
	std::cout << "s1 <= s2 ? " << (s1 <= s2) << std::endl;
	std::cout << "s1 >= s2 ? " << (s1 >= s2) << std::endl;
	std::cout << " s1 < s2 ? " << (s1 > s2) << std::endl;
	std::cout << " s1 > s2 ? " << (s1 > s2) << std::endl;
}

void	compareStack(void)
{
	compareFunc< NSP::vector<int> >("vector");
	compareFunc< std::deque<int> >("deque");
	compareFunc< std::list<int> >("list");
}
