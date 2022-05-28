/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:13 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/28 16:00:21 by lle-briq         ###   ########.fr       */
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
#include "is_integral.hpp"
#include "equal.hpp"
#include <algorithm>
#include "pair.hpp"
#include <list>

#define TESTED_TYPE int

#define T_SIZE_TYPE typename NSP::vector<T>::size_type

template <typename T>
void    printSize(NSP::vector<T> const &vct, bool print_content = true)
{
    const T_SIZE_TYPE size = vct.size();
    const T_SIZE_TYPE capacity = vct.capacity();
    const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
    // Cannot limit capacity's max value because it's implementation dependent

    std::cout << "size: " << size << std::endl;
    std::cout << "capacity: " << isCapacityOk << std::endl;
    std::cout << "max_size: " << vct.max_size() << std::endl;
    if (print_content)
    {
        typename NSP::vector<T>::const_iterator it = vct.begin();
        typename NSP::vector<T>::const_iterator ite = vct.end();
        std::cout << std::endl << "Content is:" << std::endl;
        for (; it != ite; ++it)
            std::cout << "- " << *it << std::endl;
    }
    std::cout << "###############################################" << std::endl;
}

int     main(void)
{
    std::list<TESTED_TYPE> lst;
    std::list<TESTED_TYPE>::iterator lst_it;
    for (int i = 1; i < 5; ++i)
        lst.push_back(i * 3);

    NSP::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
    printSize(vct);

    lst_it = lst.begin();
    for (int i = 1; lst_it != lst.end(); ++i)
        *lst_it++ = i * 5;
    vct.assign(lst.begin(), lst.end());
    printSize(vct);

    vct.insert(vct.end(), lst.rbegin(), lst.rend());
    printSize(vct);
    return (0);
}