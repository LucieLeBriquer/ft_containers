/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:45:48 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/21 12:24:46 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

typedef NSP::map<int, std::string>::value_type	mapPair;
typedef NSP::map<int, std::string>::iterator	mapIt;

template <typename Map, typename U>
void    insertion(Map &map, U value)
{
    NSP::pair<mapIt, bool> res;

	std::cout << YELLOW << "trying to insert (" << value.first << "," << value.second << ")" << END << std::endl;
    res = map.insert(value);
    std::cout << "[return value]\t(" << res.first->first << "," << res.first->second << ")" << std::endl;
    std::cout << "[node created]\t" << (res.second ? "yes": "no") << std::endl;
    printMap(map);
}

template <typename Map, typename U, typename V>
void    insertion(Map &map, U it, V value)
{
    mapIt	res;

	std::cout << YELLOW << "trying to insert (" << value.first << "," << value.second << ")" << END << std::endl;
    res = map.insert(it, value);
    std::cout << "[return value]\t(" << res->first << "," << res->second << ")" << std::endl;
    printMap(map);
}

void     mapInsert(void)
{
    NSP::map<int, std::string>	map;
	NSP::map<int, std::string>	map2;

	printTitle("map insertion", BORANGE);

	// classic insertion
	printSubtitle("classic insertion", ORANGE);
    insertion(map, mapPair(12, "eleven"));
	printSubtitle("insertion of a key already in map", ORANGE);
    insertion(map, mapPair(12, "twelve"));
	printSubtitle("classic insertions again", ORANGE);
    insertion(map, mapPair(42, "fourty-two"));
    insertion(map, mapPair(0, "zero"));
    insertion(map, mapPair(1, "one"));
    insertion(map, mapPair(50, "fifty"));
    insertion(map, mapPair(3, "three"));

	// insertion with hint
	printSubtitle("insertion with an hint on the same map", ORANGE);
    insertion(map, map.begin(), mapPair(2, "two"));

	// insertion with hint
	printSubtitle("insertions with hints", ORANGE);
    insertion(map2, map2.begin(), mapPair(4242, "lazy"));
    insertion(map2, map2.end(), mapPair(10, "ten"));
    insertion(map2, map2.end(), mapPair(8, "eight"));

}