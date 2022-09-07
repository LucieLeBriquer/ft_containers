/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:15:54 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/07 15:28:09 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "../iterators/reverseIterator.hpp"
# include "RedBlackTree.hpp"
# include "RedBlackIterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>,
			class Alloc = std::allocator< ft::pair<const Key,T> > >
	class map
	{
		public:

			//	typedef

			typedef typename ft::remove_const<Key>::type	key_type;
			typedef T										mapped_type;
			typedef ft::pair<key_type, T>					value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;


			//	value_compare class to compare key values

			class value_compare
			{
				friend class map;

				protected:
					key_compare	_comp;
					value_compare(key_compare c) : _comp(c) { }

				public:
					bool operator()(const value_type& x, const value_type& y) const
					{
						return (_comp(x.first, y.first));
					}
			};


		private:

			// typedef
			
			typedef Node<value_type> *NodeP;
			typedef RedBlackTree<value_type, Compare> *TreeP;
			typedef RedBlackTree<value_type, Compare> Tree;

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

			typedef RedBlackIterator<value_type, Compare, false>	iterator;
			typedef RedBlackIterator<value_type, Compare, true>		const_iterator;
			
			typedef reverseIterator<iterator>						reverse_iterator;
			typedef	reverseIterator<const_iterator>					const_reverse_iterator;


			//	constructors

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_tree(new RedBlackTree<value_type, Compare>()), _alloc(alloc), _comp(comp)
			{
				return ;
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
				_tree(new RedBlackTree<value_type, Compare>()), _alloc(alloc), _comp(comp)
			{
				while (first != last)
				{
					insert(*first);
					first++;				
				}
			}

			map(const map& x)
			{
				*this = x;
			}

			~map()
			{
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
				return (reverse_iterator(iterator(_tree, _tree->getLeaf())));
			}

			const_reverse_iterator rbegin() const
			{
				return (reverse_iterator(const_iterator(_tree, _tree->getLeaf())));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(iterator(_tree, _tree->minimum())));
			}

			const_reverse_iterator rend() const
			{
				return (reverse_iterator(const_iterator(_tree, _tree->minimum())));
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
				if (!ptr || _tree->isLeaf(ptr))
					ptr = _tree->insert(pair);
				return (ptr->value.second);
			}


			//	modifiers

			pair<iterator,bool> insert(const value_type &val)
			{
				NodeP		ptr;
				bool		alreadyMapped = true;

				ptr = _tree->search(val);
				if (!ptr)
				{
					alreadyMapped = false;
					ptr = _tree->insert(val);
				}
				return (ft::make_pair<iterator, bool>(iterator(_tree, ptr), !alreadyMapped));
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
				_tree->remove(ft::make_pair<key_type, mapped_type>(position->first, mapped_type()));
			}

			size_type	erase(const key_type& k)
			{
				return (_tree->remove(ft::make_pair<key_type, mapped_type>(k, mapped_type())) ? 1 : 0);
			}

			void		erase(iterator first, iterator last)
			{
				std::vector<key_type>	toDelete;

				while (first != last)
				{
					toDelete.push_back(first->first);
					first++;
				}
				for (size_type i = 0; i < toDelete.size(); i++)
					_tree->remove(ft::make_pair<key_type, mapped_type>(toDelete[i], mapped_type()));
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
			
			key_compare		key_comp() const
			{
				return (_comp);
			}

			value_compare	value_comp() const
			{
				return (value_compare(_comp));
			}


			// operations

			iterator		find(const key_type& k)
			{
				NodeP		ptr;
				value_type	pair(k, mapped_type());

				ptr = _tree->search(pair);
				if (!ptr)
					return (end());
				return (iterator(_tree, ptr));
			}

			const_iterator	find(const key_type& k) const
			{
				NodeP		ptr;
				value_type	pair(k, mapped_type());

				ptr = _tree->search(pair);
				if (!ptr)
					return (end());
				return (const_iterator(_tree, ptr));
			}

			size_type		count(const key_type& k) const
			{
				NodeP		ptr;
				value_type	pair(k, mapped_type());

				ptr = _tree->search(pair);
				if (!ptr)
					return (0);
				return (1);
			}
			
			iterator		lower_bound(const key_type& k)
			{
				iterator	it = begin();

				while (it != end() && _comp(it->first, k))
					it++;
				return (it);
			}

			const_iterator	lower_bound(const key_type& k) const
			{
				const_iterator	it = begin();

				while (it != end() && _comp(it->first, k))
					it++;
				return (it);
			}

			iterator		upper_bound(const key_type& k)
			{
				iterator	it = begin();

				while (it != end() && !_comp(k, it->first))
					it++;
				return (it);
			}

			const_iterator	upper_bound(const key_type& k) const
			{
				const_iterator	it = begin();

				while (it != end() && !_comp(k, it->first))
					it++;
				return (it);
			}

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
			{
				return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}

			pair<iterator,iterator>				equal_range(const key_type& k)
			{
				return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			// allocator
			allocator_type	get_allocator() const
			{
				return (allocator_type(_alloc));
			}
		};

		/*
		**		COMPARISONS
		*/

		template <class Key, class T, class Compare, class Alloc>
		bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{
			return (!(rhs < lhs));
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{
			return (rhs < lhs);
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}
}

#endif
