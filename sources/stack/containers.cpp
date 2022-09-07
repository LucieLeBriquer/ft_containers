/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:59:45 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 15:00:53 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testStack.hpp"

template<typename Container>
static void	containerStack(std::string name)
{
	printTitle("stack with " + name + " container", BORANGE);
	Container					v(10,4);
	NSP::stack<int, Container>	s(v);

	printSubtitle("initialize with v(10,4)", ORANGE);
	std::cout << "size = " << s.size() << std::endl;
	printSubtitle("push 5 elements", ORANGE);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	std::cout << "size = " << s.size() << std::endl;
	printSubtitle("pop 3 elements", ORANGE);
	s.pop();
	s.pop();
	s.pop();
	std::cout << "size = " << s.size() << std::endl;
	std::cout << "top = " << s.top() << std::endl;
	std::cout << "empty = " << s.empty() << std::endl;
}

void	constructStack(void)
{
	containerStack< NSP::vector<int> >("vector");
	containerStack< std::deque<int> >("deque");
	containerStack< std::list<int> >("list");
}