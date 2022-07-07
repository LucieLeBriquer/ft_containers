/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:15:54 by lle-briq          #+#    #+#             */
/*   Updated: 2022/07/07 17:14:10 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "reverse_iterator.hpp"
# include "RedBlackTree.hpp"
# include "rbt_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>,
			class Alloc = std::allocator< ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<Key, T>		value_type;
			typedef Compare					key_compare;
			typedef Alloc					allocator_type;

			// value_compare class to compare key values
			class value_compare
			{
				protected:
					Compare _comp;
					value_compare(Compare c) : _comp(c) { }

				public:
					//constructors
					value_compare() : _comp(Compare()) { }

					bool operator()(const value_type& x, const value_type& y) const
					{
						return (_comp(x.first, y.first));
					}
			};

		private:
			RedBlackTree<value_type, value_compare>	_tree;
			allocator_type							_alloc;
			key_compare								_comp;

		public:
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef size_t										size_type;
			typedef std::ptrdiff_t								difference_type;

			typedef	RedBlackIterator<value_type, value_compare>	rbtIterator;
			typedef rbtIterator									iterator;
			typedef rbtIterator									const_iterator;
			typedef reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;

			// constructors
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_tree(RedBlackTree<value_type, value_compare>()), _alloc(alloc), _comp(comp)
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[Map] " << END << "constructor" << std::endl;
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[Map] " << END << "iterator constructor" << std::endl;
				_alloc = alloc;
				_comp = comp;
				while (first != last)
				{
					_tree.insert(*first);
					first++;
				}
			}

			map(const map& x)
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[Map] " << END << "copy constructor" << std::endl;
				*this = x;
			}

			~map()
			{
				if (LOG >= LOG_ALL)
					std::cerr << RED << "[Map] " << END << "destructor" << std::endl;
			}

			// overload operator
			map	&operator=(const map& x)
			{
				_comp = x._comp;
				_alloc = x._alloc;
				_tree = x._tree;
				return (*this);
			}

			// iterators
			iterator begin()
			{
				return (iterator(_tree, _tree.minimum()));
			}
			
			const_iterator begin() const
			{
				return (const_iterator(_tree, _tree.minimum()));
			}

			iterator end()
			{
				return (iterator(_tree, _tree.getLeaf()));
			}

			const_iterator end() const
			{
				return (const_iterator(_tree, _tree.getLeaf()));
			}
			
			reverse_iterator rbegin()
			{
				return (reverse_iterator(iterator(_tree, _tree.maximum())));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(iterator(_tree, _tree.maximum())));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(iterator(_tree, _tree.getLeaf())));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(iterator(_tree, _tree.getLeaf())));
			}

			// capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			// element access
			mapped_type	&operator[](const key_type &k)
			{
				(void)k;
			}

			//modifiers

			/*pair<iterator,bool> insert(const value_type &val)
			{
				_tree.insert(val);
				std::cout << "wesh" << std::endl;
				return (ft::make_pair<iterator, bool>(iterator(), true));
			}*/
			// wrong type just to test
			void	insert(const value_type &val)
			{
				_tree.insert(val);
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
			allocator_type	get_allocator() const
			{
				return (allocator_type(_alloc));
			}


			//	todelete
			void	print(void) const
			{
				_tree.print();
			}
		};
}

#endif
