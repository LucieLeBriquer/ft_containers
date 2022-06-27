/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/27 12:07:52 by lle-briq         ###   ########.fr       */
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
#include <typeinfo>

int		main(void)
{
	/*ft::RedBlackTree<int, ft::less<int> >	tree;

	tree.insert(1);
	tree.printTree();
	tree.insert(40);
	tree.printTree();
	tree.insert(65);
	tree.printTree();
	tree.insert(60);
	tree.printTree();
	tree.insert(75);
	tree.printTree();
	tree.insert(57);
	tree.printTree();
	tree.test();
	tree.remove(40);
  	tree.printTree();*/
/*
	
	ft::pair<int, std::string>	pair2(3, "couocu");
	ft::pair<int, std::string>	pair3(1, "ferg");

	ft::RedBlackTree<ft::pair<int, std::string>, ft::lessKey< ft::pair<int, std::string> > >	treeMap;

	treeMap.insert(pair1);
	treeMap.insert(pair2);
	treeMap.insert(pair3);
	treeMap.printTree();*/

	ft::map<char, std::string>	map;
	ft::pair<char, std::string>	pair3('1', "ferg");
	ft::pair<char, std::string>	pair1('a', "rgeg");
	pair1 = pair3;
	pair1.first = 'n';
	std::cout << typeid(pair1).name() << std::endl;
	map.insert(pair3);
}