/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:18:58 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 18:40:37 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

static void	mapConstructionInt(void)
{
	NSP::pair<int, int>	pair1(150, 0);
	NSP::pair<int, int>	pair2(2, 1);
	NSP::pair<int, int>	pair3(100, 2);
	NSP::pair<int, int> pair4(1, 3);

	// default constructor
	NSP::map<int, int>	map;
	printTitle("map construction <int, int>", BORANGE);
	printSubtitle("default constructor", ORANGE);

	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);
	printMap(map);

	// copy constructor
	printSubtitle("copy constructor", ORANGE);
	NSP::map<int, int>	mapCopy(map);
	map.clear();
	std::cout << "original map cleared" << std::endl << std::endl;
	std::cout << YELLOW << "> copy" << END << std::endl;
	printMap(mapCopy);
	std::cout << std::endl << YELLOW << "> original"  << END << std::endl;
	printMap(map);

	// iterator constructor
	printSubtitle("iterator constructor", ORANGE);
	std::vector< NSP::pair<int, int> >	v;
	v.push_back(pair1);
	v.push_back(pair2);
	v.push_back(pair3);
	v.push_back(pair4);

	map.insert(v.rbegin(), v.rend());
	printMap(map);
}

static void	mapConstructionString(void)
{
	NSP::pair<int, std::string>	pair1(150, "string1");
	NSP::pair<int, std::string>	pair2(2, "string2");
	NSP::pair<int, std::string>	pair3(100, "string3");
	NSP::pair<int, std::string> pair4(1, "string4");

	// default constructor
	NSP::map<int, std::string>	map;
	printTitle("map construction <int, string>", BORANGE);
	printSubtitle("default constructor", ORANGE);

	map.insert(pair1);
	map.insert(pair2);
	map.insert(pair3);
	map.insert(pair4);
	printMap(map);

	// copy constructor
	printSubtitle("copy constructor", ORANGE);
	NSP::map<int, std::string>	mapCopy(map);
	map.clear();
	std::cout << "original map cleared" << std::endl << std::endl;
	std::cout << YELLOW << "> copy" << END << std::endl;
	printMap(mapCopy);
	std::cout << std::endl << YELLOW << "> original"  << END << std::endl;
	printMap(map);

	// iterator constructor
	printSubtitle("iterator constructor", ORANGE);
	std::vector< NSP::pair<int, std::string> >	v;
	v.push_back(pair1);
	v.push_back(pair2);
	v.push_back(pair3);
	v.push_back(pair4);

	map.insert(v.rbegin(), v.rend());
	printMap(map);
}

static void	mapConstructionTricky(void)
{
	printTitle("map tricky iterator construction", BORANGE);

	printSubtitle("same keys in list before construction", ORANGE);
	typedef NSP::map<int, std::string>::value_type Pair;
    std::list<Pair> lst;
    std::list<Pair>::iterator it;

    lst.push_back(Pair(1, "one"));
    lst.push_back(Pair(2, "two"));
    lst.push_back(Pair(1, "un"));
    lst.push_back(Pair(3, "three"));
    lst.push_back(Pair(4, "four"));
    lst.push_back(Pair(5, "five"));
    lst.push_back(Pair(2, "deux"));
    lst.push_back(Pair(6, "six"));
    lst.push_back(Pair(7, "seven"));
    lst.push_back(Pair(5, "cinq"));

	std::cout << "[size of list]\t" << lst.size() << std::endl;
    for (it = lst.begin(); it != lst.end(); ++it)
		printPairMap(it);
	std::cout << std::endl;

    NSP::map<int, std::string> map(lst.begin(), lst.end());
    lst.clear();
    printMap(map);
}

void	mapConstruction(void)
{
	mapConstructionString();
	mapConstructionInt();
	mapConstructionTricky();
}
