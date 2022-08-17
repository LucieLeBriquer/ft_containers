/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:22:25 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/16 17:41:44 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTMAP_HPP
# define TESTMAP_HPP
# include <map>
# include <vector>
# include "map.hpp"
# include "testUtils.hpp"

void	testMapConstruction(void);

template<typename K, typename T>
void	showMap(NSP::map<K, T> &map);

#endif
