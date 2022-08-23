/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:18:58 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/23 11:08:42 by lle-briq         ###   ########.fr       */
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
	showMap(map);

	// copy constructor
	printSubtitle("copy constructor", ORANGE);
	NSP::map<int, int>	mapCopy(map);
	map.clear();
	std::cout << "original map cleared" << std::endl << std::endl;
	std::cout << "copy :" << std::endl;
	showMap(mapCopy);
	std::cout << std::endl << "original :" << std::endl;
	showMap(map);

	// iterator constructor
	printSubtitle("iterator constructor", ORANGE);
	std::vector< NSP::pair<int, int> >	v;
	v.push_back(pair1);
	v.push_back(pair2);
	v.push_back(pair3);
	v.push_back(pair4);

	map.insert(v.rbegin(), v.rend());
	showMap(map);
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
	showMap(map);

	// copy constructor
	printSubtitle("copy constructor", ORANGE);
	NSP::map<int, std::string>	mapCopy(map);
	map.clear();
	std::cout << "original map cleared" << std::endl << std::endl;
	std::cout << "copy :" << std::endl;
	showMap(mapCopy);
	std::cout << std::endl << "original :" << std::endl;
	showMap(map);

	// iterator constructor
	printSubtitle("iterator constructor", ORANGE);
	std::vector< NSP::pair<int, std::string> >	v;
	v.push_back(pair1);
	v.push_back(pair2);
	v.push_back(pair3);
	v.push_back(pair4);

	map.insert(v.rbegin(), v.rend());
	showMap(map);
}

#define T1 int
#define T2 std::string
typedef NSP::map<T1, T2>::value_type T3;
#include <list>
static void	mapConstructionTricky(void)
{
    std::list<T3> lst;
    std::list<T3>::iterator itlst;

    lst.push_back(T3(42, "lol"));
    lst.push_back(T3(50, "mdr"));
    lst.push_back(T3(35, "funny"));
    lst.push_back(T3(45, "bunny"));
    lst.push_back(T3(21, "fizz"));
    lst.push_back(T3(35, "this key is already inside"));
    lst.push_back(T3(55, "fuzzy"));
    lst.push_back(T3(38, "buzz"));
    lst.push_back(T3(55, "inside too"));

    std::cout << "List contains: " << lst.size() << " elements." << std::endl;
    for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
        printPair(itlst);
    std::cout << "---------------------------------------------" << std::endl;

    NSP::map<T1, T2> mp(lst.begin(), lst.end());
	mp.insert(T3(42, "blblbl"));
    lst.clear();

    printMap(mp);
}

void	mapConstruction(void)
{
	mapConstructionString();
	mapConstructionInt();
	mapConstructionTricky();
}
