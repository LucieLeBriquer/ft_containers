/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:22:25 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/21 12:02:53 by lle-briq         ###   ########.fr       */
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

void	failing(void);

void	mapConstruction(void);
void	mapElementAccess(void);
void	mapIterators(void);
void	mapErase(void);
void	mapInsert(void);

template <typename T>
void	printPair(const T &iterator)
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
			printPair(it);
    }
	std::cout << std::endl;
}

template<typename K, typename T>
void	showMap(NSP::map<K, T> &map)
{
	typename NSP::map<K, T>::iterator	it = map.begin();

	while (it != map.end())
	{
		std::cout << "\t" << (*it).first << "\t:\t" << (*it).second << std::endl;
		it++;
	}
}

#endif
