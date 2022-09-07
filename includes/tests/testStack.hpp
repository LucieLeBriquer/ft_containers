/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testStack.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:37:30 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 14:37:30 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTSTACK_HPP
# define TESTSTACK_HPP
# include "testUtils.hpp"
# ifdef USESTL
#  include <stack>
#  include <vector>
# else
#  include "../stack/stack.hpp"
# endif
# include <deque>
# include <list>

void	constructStack(void);
void	compareStack(void);

#endif
