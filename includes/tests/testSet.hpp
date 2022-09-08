/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testSet.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:47:53 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 17:49:54 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TESTSET_HPP
# define TESTSET_HPP
# include <vector>
# include "testUtils.hpp"
# ifdef USESTL
#  include <set>
# else
#  include "../set/set.hpp"
# endif
# include <list>

void    setInsert(void);
void    setConstruction(void);
void	setErase(void);

template <typename T>
void	printValue(const T &iterator)
{
    std::cout << "\t" << *iterator << std::endl;
}

template <typename Set>
void    printSet(Set const &set, bool showContent = true)
{
	typedef typename Set::const_iterator mapIt;
	
    std::cout << "[size of set] \t" << set.size() << "/" << set.max_size() << std::endl;
    std::cout << "[content] " << std::endl;
    if (showContent)
    {
        mapIt	it = set.begin();
		mapIt	ite = set.end();

        for (; it != ite; ++it)
			printValue(it);
    }
	std::cout << std::endl;
}

#endif