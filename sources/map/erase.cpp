/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:54:38 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/21 12:35:53 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

#include <list>

#define T1 int
#define T2 std::string
typedef NSP::pair<const T1, T2> T3;

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
}