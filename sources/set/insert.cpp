/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:45:48 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 18:48:01 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testSet.hpp"

typedef NSP::set<int>::value_type	setVal;
typedef NSP::set<int>::iterator	setIt;

template <typename Set, typename U>
void    insertion(Set &set, U value)
{
    NSP::pair<setIt, bool> res;

	std::cout << YELLOW << "trying to insert (" << value << ")" << END << std::endl;
    res = set.insert(value);
    std::cout << "[return value]\t" << *(res.first) << std::endl;
    std::cout << "[node created]\t" << (res.second ? "yes": "no") << std::endl;
    printSet(set);
}

template <typename Set, typename U, typename V>
void    insertion(Set &set, U it, V value)
{
    setIt	res;

	std::cout << YELLOW << "trying to insert (" << value << ")" << END << std::endl;
    res = set.insert(it, value);
    std::cout << "[return value]\t" << *res  << std::endl;
    printSet(set);
}

void     setInsert(void)
{
    NSP::set<int>	set;
	NSP::set<int>	set2;

	printTitle("set insertion", BORANGE);

	// classic insertion
	printSubtitle("classic insertion", ORANGE);
    insertion(set, setVal(12));
	printSubtitle("insertion of a key already in set", ORANGE);
    insertion(set, setVal(12));
	printSubtitle("classic insertions again", ORANGE);
    insertion(set, setVal(42));
    insertion(set, setVal(0));
    insertion(set, setVal(1));
    insertion(set, setVal(50));
    insertion(set, setVal(3));

	// insertion with hint
	printSubtitle("insertion with an hint on the same set", ORANGE);
    insertion(set, set.begin(), setVal(2));

	// insertion with hint
	printSubtitle("insertions with hints", ORANGE);
    insertion(set2, set2.begin(), setVal(4242));
    insertion(set2, set2.end(), setVal(10));
    insertion(set2, set2.end(), setVal(8));

}