/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:41:12 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/21 11:50:24 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTUTILS_HPP
# define TESTUTILS_HPP
# ifdef USESTL
#  define NSP std
# else
#  define NSP ft
# endif
# define SIZE 52
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define ORANGE "\x1B[34m"
# define BYELLOW "\x1B[1;33m"
# define BORANGE "\x1B[1;34m"
# define BBLUE "\x1B[1;36m"
# define BOLD "\x1B[1m"
# define END "\x1B[0m"
# include <iostream>
# include <iomanip>

void	printTitle(std::string title, std::string color, bool toUpper = true);
void	printMainTitle(std::string title, std::string color, bool toUpper = true);
void	printSubtitle(std::string subtitle, std::string color);

#endif
