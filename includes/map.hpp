/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:15:54 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/31 20:51:05 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "normal_iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "equal.hpp"
# include "pair.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>,
		class Alloc = std::allocator< ft::pair<const Key,T> > >
	class map
	{
    public:
		typedef Key						key_type;
		typedef T						mapped_type;
		typedef ft::pair<const Key,T>	value_type;
		typedef Compare					key_compare;
		typedef Alloc					allocator_type;

	private:
		//typedef	ft::binarySearchTree<value_type, Compare>	bst;
		bst				_tree;
		allocator_type	_alloc;
		key_compare		_comp;

	public:

		class value_compare
		{
			protected:
				Compare _comp;
				value_compare(Compare c) : _comp(c) { }

			public:
			bool operator()(const value_type& x, const value_type& y) const
			{
				return _comp(x.first, y.first);
			}
		};

		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
      	typedef normal_iterator<pointer, map>				iterator;
      	typedef normal_iterator<const_pointer, map>			const_iterator;
      	typedef reverse_iterator<const_iterator>			const_reverse_iterator;
      	typedef reverse_iterator<iterator>					reverse_iterator;
      	typedef size_t										size_type;
      	typedef std::ptrdiff_t								difference_type;

		// constructors
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_tree(bst(comp))
		{
			(void)alloc;
			//
		}

		template <class InputIterator>
  		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		{
			(void)first;
			(void)last;
			(void)comp;
			(void)alloc;
		}

		map(const map& x)
		{
			*this = x;
		}

		~map()
		{ 
			//
		}

		// overload operator
		map	&operator=(const map& x)
		{
			_comp = x._comp;
			_alloc = x._alloc;
			_tree = x._tree;
		}

		// iterators
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// capacity
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		// element access
		mapped_type	&operator[](const key_type& k)
		{
			value_type			defaultPair = ft::make_pair<const Key, T>(k, T());
			Node<value_type>	*node = _tree.research(defaultPair);

			if (!node)
			{
				_tree.insert(defaultPair);
				return (T());
			}
			return (node->value.second);
		}

		//modifiers

		pair<iterator,bool> insert(const value_type& val)
		{
			pair<iterator, bool>	ret;
			Node<value_type>		*node;

			node = _tree.research(val);
			if (node)
				return (ft::make_pair<iterator, bool>(node, false));
			_tree.insert(val);
			node = _tree.research(val);
			return (ft::make_pair<iterator, bool>(node, true)); 
		}
		iterator	insert(iterator position, const value_type& val);
		
		template <class InputIterator>
  		void		insert(InputIterator first, InputIterator last);

		void 		erase(iterator position);
		size_type	erase(const key_type& k);
     	void		erase(iterator first, iterator last);
		void		swap(map& x);
		void		clear();

		// observers
		key_compare		key_comp() const;
		value_compare	value_comp() const;

		// operations
		iterator		find(const key_type& k);
		const_iterator	find(const key_type& k) const;
		size_type		count(const key_type& k) const;
		iterator		lower_bound(const key_type& k);
		const_iterator	lower_bound(const key_type& k) const;
		iterator		upper_bound(const key_type& k);
		const_iterator	upper_bound(const key_type& k) const;
		pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
		pair<iterator,iterator>				equal_range(const key_type& k);

		// allocator
		allocator_type	get_allocator() const;

	};
}

#endif
