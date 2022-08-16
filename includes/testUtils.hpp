/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:41:12 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/16 17:42:32 by lle-briq         ###   ########.fr       */
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
# define ORANGE "\x1B[34m"
# define BORANGE "\x1B[1;34m"
# define BOLD "\x1B[1m"
# define END "\x1B[0m"
# include <iostream>
# include <iomanip>

void	printTitle(std::string title, std::string color, bool toUpper = true);
void	printSubtitle(std::string subtitle, std::string color);

#endif
