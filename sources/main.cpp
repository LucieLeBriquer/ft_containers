/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/30 19:25:51 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "iterators_traits.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
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
#else
# define NSP ft
#endif
#define SIZE 60

#include <typeinfo>

int	main(void)
{
	typedef ft::iterator_traits< std::vector<int>::iterator >	traits;

	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
		std::cout << "it RAIT" << std::endl;

	std::vector<int>	v(10);
	v.push_back(3);

	ft::reverse_iterator< std::vector<int>::iterator >	rev_it(v.begin());
	std::reverse_iterator< std::vector<int>::iterator >	rev_it_std(v.begin());

	std::cout << (rev_it_std.base() == rev_it.base()) << std::endl;


	return (0);
}
