/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/27 19:29:15 by lle-briq         ###   ########.fr       */
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

int		main(void)
{
	ft::map<int, std::string>	map;
	ft::pair<int, std::string>	pair1(150, "lucie");
	ft::pair<int, std::string>	pair2(2, "jonathan");
	ft::pair<int, std::string>	pair3(100, "lise");
	ft::map<int, std::string>::iterator	it;

	map.insert(pair3);
	map.insert(pair2);
	map.insert(pair1);
	map.insert(pair1);
	it = map.begin();
	std::cout << *(it).first << std::endl;
	map.print();
}