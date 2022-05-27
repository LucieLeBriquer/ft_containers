/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/27 15:38:01 by lle-briq         ###   ########.fr       */
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
# define ISFT 0
#else
# define NSP ft
# define ISFT 1
#endif
#define SIZE 60

#include <typeinfo>
#include <type_traits>
#include "is_integral.hpp"
#include "equal.hpp"
#include <algorithm>
#include "pair.hpp"

template<class T>
void	show(NSP::vector<T> v)
{
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "[" << v.size() << "/" << v.capacity() << "]" << std::endl;
}

int	main(void)
{
	NSP::vector<float>	v(15,10);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	NSP::vector<float>	v2(v.begin(), v.end());
	NSP::vector<float>	v3(v.rbegin(), v.rend());

	//show(v2);
	//show(v3);
	v2.resize(10);
	v3.resize(20, 1.3);
	//show(v2);
	//show(v3);
	std::cout << "front = " << v2.front() << "  back = " << v2.back() << std::endl;
	std::cout << "front = " << v3.front() << "  back = " << v3.back() << std::endl;
	try {
		std::cout << v3.at(50) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
