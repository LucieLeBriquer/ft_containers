/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:12:47 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/31 21:19:06 by lle-briq         ###   ########.fr       */
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
		Node*		left;
		Node*		right;

		// constructor
		Node() : value(value_type()), left(NULL), right(NULL)
		{
			return ;
		}

		Node(Node* left = NULL, Node* right = NULL) :
			value(value_type()), left(left), right(right)
		{
			return ;
		}
		
		Node(const value_type& val, Node* left = NULL, Node* right = NULL) :
			value(val), left(left), right(right)
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
				this->left = node.left;
				this->right = node.right;
			}
			return (*this);
		}
    };

	template <typename T>
	Node<T>	*getNext(Node<T> *node)
	{
		Node<T>	*curr;
		if (!node || !(node->right))
			return (NULL);
		curr = node->right;
		while (curr->left)
			curr = curr->left;
		return (curr);
	}

	template <typename T>
	Node<T>	*getPrev(Node<T> *node)
	{
		Node<T>	*curr;
		if (!node || !(node->left))
			return (NULL);
		curr = node->left;
		while (curr->right)
			curr = curr->right;
		return (curr);
	}
}

#endif
