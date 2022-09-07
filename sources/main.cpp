/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 13:04:17 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"
#include "testVector.hpp"

static void	testMap(void)
{
	printMainTitle("map", BORANGE);
	mapConstruction();
	mapElementAccess();
	mapIterators();
	mapInsert();
	mapErase();
	mapObservers();
	mapFind();
	mapBound();
}

static void	testVector(void)
{
	printMainTitle("vector", BORANGE);
	vectorConstruction();
	vectorInsert();
	vectorErase();
	vectorAccess();
	vectorIterators();
	vectorCompare();
}

static void	testStack(void)
{

}

typedef void (*testFunction)(void);

static void testContainer(const std::string &str)
{
	const int			nbContainers = 3;
	const std::string	containers[nbContainers] = { "vector", "map", "stack" };
	testFunction		func[nbContainers] = { testVector, testMap, testStack };
	int					idContainer = -1;

	for (int i = 0; i < nbContainers; i++)
	{
		if (str == containers[i])
		{
			idContainer = i;
			break;
		}
	}
	if (idContainer >= 0)
		func[idContainer]();
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		testMap();
		testVector();
	}
	else
	{
		for (int i = 1; i < argc; i++)
			testContainer(std::string(argv[i]));	
	}
	return (0);
}
