/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:15:54 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/19 10:52:31 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "reverse_iterator.hpp"
# include "RedBlackTree.hpp"
# include "rbt_iterator.hpp"
# include "normal_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>,
			class Alloc = std::allocator< ft::pair<const Key,T> > >
	class map
	{
		public:

			//	typedef

			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<Key, T>		value_type;
			typedef Compare					key_compare;
			typedef Alloc					allocator_type;


			//	value_compare class to compare key values

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
			// typedef
			
			typedef Node<value_type> *NodeP;
			typedef RedBlackTree<value_type, value_compare> *TreeP;
			typedef RedBlackTree<value_type, value_compare> Tree;

			TreeP									_tree;
			allocator_type							_alloc;
			key_compare								_comp;


		public:

			//	typedef

			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef size_t												size_type;
			typedef std::ptrdiff_t										difference_type;


		public:

			typedef RedBlackIterator<value_type, value_compare, false>		iterator;
			typedef RedBlackIterator<value_type, value_compare, true>		const_iterator;
			typedef	RedBlackIteratorRev<value_type, value_compare, false>	reverse_iterator;
			typedef	RedBlackIteratorRev<value_type, value_compare, true>	const_reverse_iterator;


			//	constructors

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_tree(new RedBlackTree<value_type, value_compare>()), _alloc(alloc), _comp(comp)
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[Map] " << END << "constructor" << std::endl;
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
				_tree(new RedBlackTree<value_type, value_compare>()), _alloc(alloc), _comp(comp)
			{
				if (LOG >= LOG_ALL)
					std::cerr << GREEN << "[Map] " << END << "iterator constructor" << std::endl;
				while (first != last)
				{
					_tree->insert(*first);
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
				delete _tree;
			}


			//	overload operator

			map	&operator=(const map& x)
			{
				if (this != &x)
				{
					_comp = x._comp;
					_alloc = x._alloc;
					_tree = new Tree(*(x._tree));
				}
				return (*this);
			}


			//	iterators

			iterator begin()
			{
				return (iterator(_tree, _tree->minimum()));
			}
			
			const_iterator begin() const
			{
				return (const_iterator(_tree, _tree->minimum()));
			}

			iterator end()
			{
				return (iterator(_tree, _tree->getLeaf()));
			}

			const_iterator end() const
			{
				return (const_iterator(_tree, _tree->getLeaf()));
			}
			
			reverse_iterator rbegin()
			{
				return (reverse_iterator(_tree, _tree->maximum()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(_tree, _tree->maximum()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(_tree, _tree->getLeaf()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_tree, _tree->getLeaf()));
			}


			//	capacity

			bool empty() const
			{
				return (_tree->getRoot() == _tree->getLeaf());
			}

			size_type size() const
			{
				return (_tree->size());
			}

			size_type max_size() const
			{
				return (_tree->maxSize());
			};


			//	element access

			mapped_type	&operator[](const key_type &k)
			{
				value_type	pair(k, mapped_type());
				NodeP		ptr;

				ptr = _tree->search(pair);
				if (!ptr || ptr->isLeaf)
					ptr = _tree->insert(pair);
				return (ptr->value.second);
			}


			//	modifiers

			pair<iterator,bool> insert(const value_type &val)
			{
				NodeP		ptr;
				bool		alreadyMapped = true;

				ptr = _tree->search(val);
				if (!ptr || ptr->isLeaf)
				{
					alreadyMapped = false;
					ptr = _tree->insert(val);
				}
				return (ft::make_pair<iterator, bool>(iterator(_tree, ptr), alreadyMapped));
			}

			iterator	insert(iterator position, const value_type& val)
			{
				(void)position;
				return (insert(val).first);
			}
			
			template <class InputIterator>
			void		insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void 		erase(iterator position)
			{
				_tree->remove(position.base());
			}

			size_type	erase(const key_type& k)
			{
				return (_tree->remove(ft::make_pair<key_type, mapped_type>(k, mapped_type())) ? 1 : 0);
			}

			void		erase(iterator first, iterator last)
			{
				while (first != last)
				{
					_tree->remove(first->base());
					first++;
				}
			}

			void		swap(map& x)
			{
				TreeP			saveTree = _tree;
				allocator_type	saveAlloc = _alloc;
				key_compare		saveComp = _comp;

				_tree = x._tree;
				_alloc = x._alloc;
				_comp = x._comp;
				x._tree = saveTree;
				x._alloc = saveAlloc;
				x._comp = saveComp;
			}

			void		clear()
			{
				_tree->clear();
			}


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
				_tree->print();
			}
		};
}

#endif
