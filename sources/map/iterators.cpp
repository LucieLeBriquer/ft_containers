/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:03:17 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/19 15:03:32 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

void     mapIterators(void)
{
    NSP::map<int, int>					map;
    NSP::map<int, int>::iterator		it = map.begin();
    NSP::map<int, int>::const_iterator	cit = map.begin();

    NSP::map<int, int>::reverse_iterator		rit(it);

    NSP::map<int, int>::const_reverse_iterator	crit(rit);
    NSP::map<int, int>::const_reverse_iterator	crit2(it);
    NSP::map<int, int>::const_reverse_iterator	crit3(cit);

	//shouldn't compile
    //NSP::map<int, int>::reverse_iterator	rit2(crit);
    //NSP::map<int, int>::reverse_iterator 	rit3(cit);
    //NSP::map<int, int>::iterator 			it2(rit);
    //NSP::map<int, int>::const_iterator 	cit2(crit);

    std::cout << "OK" << std::endl;
}