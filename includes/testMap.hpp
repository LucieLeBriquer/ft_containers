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

void	mapConstruction(void);
void	elementAccess(void);

template<typename K, typename T>
void	showMap(NSP::map<K, T> &map);

#endif
