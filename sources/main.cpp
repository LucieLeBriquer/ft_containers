/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/31 18:26:37 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "map.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#define RED "\x1B[31m"
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

namespace ft
{
	template<typename K, typename T>
	struct test
	{
		bool operator()(const ft::pair<K, T> & a, const ft::pair<K, T> & b) const
		{
			return (a.first < b.first);
		}
	};
}

int		main(void)
{
	ft::binarySearchTree< ft::pair<int, std::string>, ft::test<int, std::string> > bst;

	bst.insert(ft::make_pair<int, std::string>(2, "deux"));
	bst.insert(ft::make_pair<int, std::string>(1, "un"));
	bst.insert(ft::make_pair<int, std::string>(3, "trois"));
	std::cout << bst.research(ft::make_pair<int, std::string>(1, ""))->value.second << std::endl;
	std::cout << bst.research(ft::make_pair<int, std::string>(2, ""))->value.second << std::endl;
	std::cout << bst.research(ft::make_pair<int, std::string>(3, ""))->value.second << std::endl;
	
}