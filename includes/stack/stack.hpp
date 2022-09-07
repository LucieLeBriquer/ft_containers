/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:09:55 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 14:33:21 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
    	typedef T			value_type;
      	typedef Container	container_type;
      	typedef size_t		size_type;

	protected:
		container_type		_container;

	public:

		// constructors and destructor

		explicit	stack(const container_type& ctnr = container_type()) : _container(ctnr)
		{
			return ;
		}

		stack(const stack &st) : _container(st._container)
		{
			return ;
		}

		stack		&operator=(const stack& other)
		{
			_container = other._container;
			return (*this);
		}

		~stack()
		{
			return ;
		}


		// member functions

		bool	empty() const
		{
			return (_container.empty());
		}

		size_type	size() const
		{
			return (_container.size());
		}

		value_type	&top()
		{
			return (_container.back());
		}

		const value_type	&top() const
		{
			return (_container.back());
		}

		void	push(const value_type& val)
		{
			_container.push_back(val);
		}

		void	pop()
		{
			_container.pop_back();
		}

		void	swap(stack &x)
		{
			_container.swap(x._container);
		}


		// compare

		friend bool operator==(const stack& lhs, const stack& rhs)
		{
			return (lhs._container == rhs._container);
		}

		friend bool operator!=(const stack& lhs, const stack& rhs)
		{
			return (lhs._container != rhs._container);
		}

		friend bool operator<(const stack& lhs, const stack& rhs)
		{
			return (lhs._container < rhs._container);
		}

		friend bool operator>(const stack& lhs, const stack& rhs)
		{
			return (lhs._container > rhs._container);
		}

		friend bool operator<=(const stack& lhs, const stack& rhs)
		{
			return (lhs._container <= rhs._container);
		}

		friend bool operator>=(const stack& lhs, const stack& rhs)
		{
			return (lhs._container >= rhs._container);
		}
	};
}

#endif
