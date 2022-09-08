/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:54:38 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 19:02:09 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testSet.hpp"

template <typename Set, typename U>
void	eraseAndPrint(Set &set, U val)
{
	set.erase(val);
	printSet(set);
}
template <typename Set, typename U, typename V>
void	eraseAndPrint(Set &set, U start, V end)
{
	set.erase(start, end);
	printSet(set);
}

typedef std::string Value;

void	setErase(void)
{
	printTitle("set erase", BORANGE);
	std::list<Value> lst;

    lst.push_back(Value("one"));
    lst.push_back(Value("two"));
    lst.push_back(Value("three"));
    lst.push_back(Value("four"));
    lst.push_back(Value("five"));
    lst.push_back(Value("six"));
    lst.push_back(Value("seven"));
    lst.push_back(Value("eight"));
    lst.push_back(Value("nine"));
    lst.push_back(Value("ten"));

    NSP::set<std::string> set(lst.begin(), lst.end());
	std::cout << std::endl;
	printSet(set);

	std::cout << YELLOW << "erase(begin(), begin() + 2)" << END << std::endl;
	set.erase(set.begin(), ++(++(set.begin())));
	printSet(set);

	std::cout << YELLOW << "erase(begin())" << END << std::endl;
	eraseAndPrint(set, set.begin());

	std::cout << YELLOW << "erase(--end())" << END << std::endl;
    eraseAndPrint(set, --set.end());

	std::cout << YELLOW << "erase(begin(), begin() + 3)" << END << std::endl;
    eraseAndPrint(set, set.begin(), ++(++(++set.begin())));

	std::cout << YELLOW << "erase(end() - 3, end() - 1)" << END << std::endl;
    eraseAndPrint(set, --(--(--set.end())), --set.end());

	std::cout << YELLOW << "erase(begin(), end())" << END << std::endl;
    eraseAndPrint(set, set.begin(), set.end());
}
