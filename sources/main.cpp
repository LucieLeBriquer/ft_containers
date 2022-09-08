/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/08 12:35:31 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testMap.hpp"
#include "testVector.hpp"
#include "testStack.hpp"
#include "testSet.hpp"

typedef void (*testFunction)(void);

static void	testMap(void)
{
	printMainTitle("map", BORANGE);
	mapBound();
	mapConstruction();
	mapElementAccess();
	mapErase();
	mapFind();
	mapIterators();
	mapInsert();
	mapObservers();
}

static void	testSet(void)
{
	printMainTitle("set", BORANGE);
	setBound();
	setConstruction();
	setErase();
	setFind();
	setInsert();
	setIterators();
	setObservers();
}

static void	testVector(void)
{
	printMainTitle("vector", BORANGE);
	vectorAccess();
	vectorCompare();
	vectorConstruction();
	vectorErase();
	vectorInsert();
	vectorIterators();
}

static void	testStack(void)
{
	printMainTitle("stack", BORANGE);
	constructStack();
	compareStack();
}

static void	testSubject(void)
{
	printMainTitle("subject", BORANGE);
	subjectTest();
}

static void testContainer(const std::string &str)
{
	const int			nbContainers = 5;
	const std::string	containers[nbContainers] = { "vector", "map", "stack", "set", "subject" };
	testFunction		func[nbContainers] = { testVector, testMap, testStack, testSet, testSubject };
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
		testStack();
		testSet();
	}
	else
	{
		for (int i = 1; i < argc; i++)
			testContainer(std::string(argv[i]));	
	}
	return (0);
}
