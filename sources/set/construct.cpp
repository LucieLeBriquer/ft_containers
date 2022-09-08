/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:18:58 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 18:56:12 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testSet.hpp"

static void	setConstructionInt(void)
{
	int	val1(150);
	int	val2(2);
	int	val3(100);
	int val4(1);

	// default constructor
	NSP::set<int>	set;
	printTitle("set construction <int>", BORANGE);
	printSubtitle("default constructor", ORANGE);

	set.insert(val1);
	set.insert(val2);
	set.insert(val3);
	set.insert(val4);
	printSet(set);

	// copy constructor
	printSubtitle("copy constructor", ORANGE);
	NSP::set<int>	setCopy(set);
	set.clear();
	std::cout << "original set cleared" << std::endl << std::endl;
	std::cout << YELLOW << "> copy" << END << std::endl;
	printSet(setCopy);
	std::cout << std::endl << YELLOW << "> original"  << END << std::endl;
	printSet(set);

	// iterator constructor
	printSubtitle("iterator constructor", ORANGE);
	std::vector< int >	v;
	v.push_back(val1);
	v.push_back(val2);
	v.push_back(val3);
	v.push_back(val4);

	set.insert(v.rbegin(), v.rend());
	printSet(set);
}

static void	setConstructionString(void)
{
	std::string	val1("string1");
	std::string	val2("string2");
	std::string	val3("string3");
	std::string val4("string4");

	// default constructor
	NSP::set<std::string>	set;
	printTitle("set construction <string>", BORANGE);
	printSubtitle("default constructor", ORANGE);

	set.insert(val1);
	set.insert(val2);
	set.insert(val3);
	set.insert(val4);
	printSet(set);

	// copy constructor
	printSubtitle("copy constructor", ORANGE);
	NSP::set<std::string>	setCopy(set);
	set.clear();
	std::cout << "original set cleared" << std::endl << std::endl;
	std::cout << YELLOW << "> copy" << END << std::endl;
	printSet(setCopy);
	std::cout << std::endl << YELLOW << "> original"  << END << std::endl;
	printSet(set);

	// iterator constructor
	printSubtitle("iterator constructor", ORANGE);
	std::vector< std::string >	v;
	v.push_back(val1);
	v.push_back(val2);
	v.push_back(val3);
	v.push_back(val4);

	set.insert(v.rbegin(), v.rend());
	printSet(set);
}

static void	setConstructionTricky(void)
{
	printTitle("set tricky iterator construction", BORANGE);

	printSubtitle("same keys in list before construction", ORANGE);
	typedef NSP::set<std::string>::value_type Value;
    std::list<Value> lst;
    std::list<Value>::iterator it;

    lst.push_back(Value("one"));
    lst.push_back(Value("two"));
    lst.push_back(Value("un"));
    lst.push_back(Value("three"));
    lst.push_back(Value("four"));
    lst.push_back(Value("five"));
    lst.push_back(Value("deux"));
    lst.push_back(Value("six"));
    lst.push_back(Value("seven"));
    lst.push_back(Value("cinq"));

	std::cout << "[size of list]\t" << lst.size() << std::endl;
    for (it = lst.begin(); it != lst.end(); ++it)
		printValue(it);
	std::cout << std::endl;

    NSP::set<std::string> set(lst.begin(), lst.end());
    lst.clear();
    printSet(set);
}

void	setConstruction(void)
{
	setConstructionString();
	setConstructionInt();
	setConstructionTricky();
}
