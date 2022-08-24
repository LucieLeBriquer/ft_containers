/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:54:38 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/23 18:33:12 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

template <typename Map, typename U>
void	eraseAndPrint(Map &map, U val)
{
	map.erase(val);
	printMap(map);
}
template <typename Map, typename U, typename V>
void	eraseAndPrint(Map &map, U start, V end)
{
	map.erase(start, end);
	printMap(map);
}

typedef NSP::pair<const int, std::string> Pair;

void	mapErase(void)
{
	printTitle("map erase", BORANGE);
	std::list<Pair> lst;

    lst.push_back(Pair(1, "one"));
    lst.push_back(Pair(2, "two"));
    lst.push_back(Pair(3, "three"));
    lst.push_back(Pair(4, "four"));
    lst.push_back(Pair(5, "five"));
    lst.push_back(Pair(6, "six"));
    lst.push_back(Pair(7, "seven"));
    lst.push_back(Pair(8, "eight"));
    lst.push_back(Pair(9, "nine"));
    lst.push_back(Pair(10, "ten"));

    NSP::map<int, std::string> map(lst.begin(), lst.end());
	std::cout << std::endl;
	printMap(map);

	std::cout << YELLOW << "erase(begin(), begin() + 2)" << END << std::endl;
	map.erase(map.begin(), ++(++(map.begin())));
	printMap(map);

	std::cout << YELLOW << "erase(begin())" << END << std::endl;
	eraseAndPrint(map, map.begin());

	std::cout << YELLOW << "erase(--end())" << END << std::endl;
    eraseAndPrint(map, --map.end());

	std::cout << YELLOW << "erase(begin(), begin() + 3)" << END << std::endl;
    eraseAndPrint(map, map.begin(), ++(++(++map.begin())));

	std::cout << YELLOW << "erase(end() - 3, end() - 1)" << END << std::endl;
    eraseAndPrint(map, --(--(--map.end())), --map.end());

	std::cout << YELLOW << "assign some value" << END << std::endl;
	std::cout << YELLOW << "" << END << std::endl;
    map[12] = "twelve";
    map[13] = "thirteen";
    map[14] = "fourteen";
    map[15] = "fifteen";
    printMap(map);

	std::cout << YELLOW << "erase(begin(), end())" << END << std::endl;
    eraseAndPrint(map, map.begin(), map.end());
}
