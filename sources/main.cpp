/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/29 19:01:06 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "map.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define ORANGE "\x1B[34m"
#define PURPLE "\x1B[35m"
#define BLUE "\x1B[36m"
#define BOLD "\x1B[1m"
#define END "\x1B[0m"
#ifdef USESTL
# define NSP std
# define ISFT 0
#else
# define NSP ft
# define ISFT 1
#endif
#define SIZE 60
/*
void		testMap(void)
{
	NSP::map<int, std::string>	map;
	NSP::pair<int, std::string>	pair1(150, "lucie");
	NSP::pair<int, std::string>	pair2(2, "jonathan");
	NSP::pair<int, std::string>	pair3(100, "lise");
	NSP::pair<int, std::string> pair4(1, "soji");
	NSP::map<int, std::string>::iterator			it;
	NSP::map<int, std::string>::reverse_iterator	rit;

	map.insert(pair3);
	map.insert(pair2);
	map.insert(pair1);
	map.insert(pair4);
	//map.print();
	it = map.begin();
	int i = 0;
	while (it != map.end())
	{
		std::cout << "[" << i << "] " << it->first << " : " << it->second << std::endl;
		it++;
		i++;
	}
	std::cout << std::endl;
	rit = map.rbegin();
	i = 0;
	while (rit != map.rend())
	{
		std::cout << "[" << i << "] " << rit->first << " : " << rit->second << std::endl;
		rit++;
		i++;
	}
}
*/
void	printSize(NSP::vector<int> vct)
{
	for (size_t i = 0; i < vct.size(); i++)
		std::cout << vct[i] << " ";
	std::cout << std::endl;
}

int     main(void)
{
    const int size = 5;
    NSP::vector<int> vct(size);
    NSP::vector<int>::iterator it_ = vct.begin();
    NSP::vector<int>::reverse_iterator it(it_);

    for (int i = 0; i < size; ++i)
        vct[i] = (i + 1) * 5;
    printSize(vct);

    //std::cout << (it_ == it.base()) << std::endl;
    //std::cout << (it_ == (it + 3).base()) << std::endl;
	std::cout << *it << std::endl;
	std::cout << *it_ << std::endl;

    std::cout << *(it.base() + 1) << std::endl;
    std::cout << *(it - 3) << std::endl;
    std::cout << *(it - 3).base() << std::endl;
    it -= 3;
    std::cout << *it.base() << std::endl;

    std::cout << "TEST OFFSET" << std::endl;
    std::cout << *(it) << std::endl;
    std::cout << *(it).base() << std::endl;
    std::cout << *(it - 0) << std::endl;
    std::cout << *(it - 0).base() << std::endl;
    std::cout << *(it - 1).base() << std::endl;

    return (0);
}