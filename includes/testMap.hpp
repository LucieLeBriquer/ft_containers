/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:22:25 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/17 17:51:56 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTMAP_HPP
# define TESTMAP_HPP
# ifdef USESTL
#  include <map>
# else
#  include "map.hpp"
# endif
# include <vector>
# include "testUtils.hpp"

template<typename K, typename T>
void	showMap(NSP::map<K, T> &map);

void	mapConstruction(void);
void	mapElementAccess(void);
void	mapIterators(void);
void	mapErase(void);

#endif
