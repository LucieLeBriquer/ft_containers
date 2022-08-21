/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:54:38 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/21 17:09:54 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

#include <list>

#define T1 int
#define T2 std::string
typedef NSP::pair<const T1, T2> T3;

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

void	mapErase(void)
{
	std::list<T3> lst;
    unsigned int lst_size = 10;
    for (unsigned int i = 0; i < lst_size; ++i)
        lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
    NSP::map<T1, T2> map(lst.begin(), lst.end());

	printMap(map);
	map.erase(map.begin(), ++(++(map.begin())));
	printMap(map);

	eraseAndPrint(map, map.begin());
    eraseAndPrint(map, --map.end());

    eraseAndPrint(map, map.begin(), ++(++(++map.begin())));
    eraseAndPrint(map, --(--(--map.end())), --map.end());

    map[10] = "Hello";
    map[11] = "Hi there";
    printMap(map);
    eraseAndPrint(map, --(--(--map.end())), map.end());

    map[12] = "ONE";
    map[13] = "TWO";
    map[14] = "THREE";
    map[15] = "FOUR";
    printMap(map);
    eraseAndPrint(map, map.begin(), map.end());
}
