/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/07 18:32:12 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "reverse_iterator.hpp"
#include "normal_iterator.hpp"
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
#include <type_traits>
#include "is_integral.hpp"
#include "equal.hpp"
#include <algorithm>

int	main(void)
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	it2;
	ft::is_integral<int> t;


	std::vector<int>	v(10);
	std::vector<int>	v2(11);

	std::cout << std::equal(v.begin(), v.end(), v2.begin()) << std::endl;
	std::cout << ft::equal(v.begin(), v.end(), v2.begin()) << std::endl;

	it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	return (0);
}
