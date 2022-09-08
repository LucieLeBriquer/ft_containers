/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:22:25 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 18:40:37 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTMAP_HPP
# define TESTMAP_HPP
# include <vector>
# include "testUtils.hpp"
# ifdef USESTL
#  include <map>
# else
#  include "../map/map.hpp"
# endif
# include <list>

void	mapConstruction(void);
void	mapElementAccess(void);
void	mapIterators(void);
void	mapErase(void);
void	mapInsert(void);
void	mapObservers(void);
void	mapFind(void);
void	mapBound(void);

template <typename T>
void	printPairMap(const T &iterator)
{
    std::cout << "\t" << std::setfill(' ') << std::setw(6) << iterator->first;
	std::cout << "\t" << iterator->second << std::endl;
}

template <typename Map>
void    printMap(Map const &mp, bool showContent = true)
{
	typedef typename Map::const_iterator mapIt;
	
    std::cout << "[size of map] \t" << mp.size() << "/" << mp.max_size() << std::endl;
    std::cout << "[content] " << std::endl;
    if (showContent)
    {
        mapIt	it = mp.begin();
		mapIt	ite = mp.end();

        for (; it != ite; ++it)
			printPairMap(it);
    }
	std::cout << std::endl;
}

template <typename Map>
void    printMapRev(Map const &mp, bool showContent = true)
{
	typedef typename Map::const_iterator mapIt;
	
    std::cout << "[size of map] \t" << mp.size() << "/" << mp.max_size() << std::endl;
    std::cout << "[reverse content] " << std::endl;
    if (showContent)
    {
        mapIt	it = mp.end();
		mapIt	ite = mp.begin();

        while (it != ite)
		{
			it--;
			printPairMap(it);
		}
    }
	std::cout << std::endl;
}

#endif
