/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:12:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/28 17:12:47 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft 
{
    template <typename T>
    struct Node
    {
	public :
		typedef T   value_type;

		value_type	value;
		Node*		parent;
		Node*		left;
		Node*		right;

		// constructor
		Node() : value(value_type()), parent(NULL), left(NULL), right(NULL)
		{
			return ;
		}

		Node(Node* parent, Node* left = NULL, Node* right = NULL) :
			value(value_type()), parent(parent), left(left), right(right)
		{
			return ;
		}
		
		Node(const value_type& val, Node* parent = NULL, Node* left = NULL, Node* right = NULL) :
			value(val), parent(parent), left(left), right(right)
		{
			return ;
		}

		Node(const Node& node)
		{
			*this = node;
		}

		virtual ~Node(){}

		// overload operators
		Node &operator=(const Node& node)
		{
			if (*this != node)
			{
				this->value = node.value;
				this->parent = node.parent;
				this->left = node.left;
				this->right = node.right;
			}
			return (*this);
		}

		bool operator==(const Node& node)
		{
			if (value == node.value)
				return (true);
			return (false);
		}
    };

}

#endif
