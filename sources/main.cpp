/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/16 15:27:40 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"

int	main(void)
{
	/*
	**		MAP
	*/

	// construction
	mapConstruction();
	return (0);	
	// element access
	mapElementAccess();

	// iterators
	mapIterators();
	
	// insertion
	mapInsert();

	// erase
	mapErase();

}
