/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:17:15 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 10:19:46 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTVECTOR_HPP
# define TESTVECTOR_HPP
# include "testUtils.hpp"
# include <list>
# ifdef USESTL
#  include <vector>
# else
#  include "../vector/vector.hpp"
# endif
#endif

void	vectorConstruction(void);
void	vectorInsert(void);
void	vectorErase(void);
void	vectorAccess(void);
void	vectorIterators(void);

template <typename Vector>
void	printVector(const Vector &v, bool showContent = true)
{
	typedef typename Vector::const_iterator vecIt;
	
    std::cout << "[size of vector] \t" << v.size() << std::endl;
    std::cout << "[content] " << std::endl;
    if (showContent)
    {
        vecIt	it = v.begin();
		vecIt	ite = v.end();

        for (; it != ite; ++it)
			std::cout << *it << " ";
    }
	std::cout << std::endl;
}
