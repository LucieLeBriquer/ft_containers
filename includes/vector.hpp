/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:36:29 by lle-briq          #+#    #+#             */
/*   Updated: 2022/05/28 15:57:35 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "normal_iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include <memory>
# include <iostream>
# include <cstddef>
# include <stdexcept>
# include <sstream>

namespace ft
{
  	template< typename T, typename Alloc = std::allocator<T> >
	class vector
    {

    public:
    	typedef T											value_type;
      	typedef Alloc										allocator_type;
    	typedef typename allocator_type::pointer			pointer;
    	typedef typename allocator_type::const_pointer		const_pointer;
      	typedef typename allocator_type::reference			reference;
      	typedef typename allocator_type::const_reference	const_reference;
      	typedef normal_iterator<pointer, vector>			iterator;
      	typedef normal_iterator<const_pointer, vector>		const_iterator;
      	typedef reverse_iterator<const_iterator>			const_reverse_iterator;
      	typedef reverse_iterator<iterator>					reverse_iterator;
      	typedef size_t										size_type;
      	typedef std::ptrdiff_t								difference_type;
		
	protected:
		pointer					_base;
		size_type				_capacity;
		size_type				_size;
		allocator_type			_alloc;

		static size_type	_closestPow2(size_type n)
		{
			size_type	i = 1;

			while (i < n)
				i *= 2;
			return (i);
		}

		std::string			_msgOutOfRange(size_type n) const
		{
			std::stringstream	ss;

			ss << "ft::vector::_M_range_check: __n (which is ";
			ss << n;
			ss << ") >= this->size() (which is ";
			ss << _size << ")";
			return (ss.str());
		}

	public:
	
		// constructors and destructor
      	explicit vector(void) : _base(NULL), _capacity(0), _size(0), _alloc(allocator_type()) { }
		
		explicit vector(size_type n, const value_type& val = value_type()) :
			_base(NULL), _capacity(0), _size(0), _alloc(allocator_type())
		{
			assign(n, val);
		}

		template <class It>
		vector(It first, It last, typename ft::enable_if<!ft::is_integral<It>::value, It>::type* = 0):
			_base(NULL), _capacity(0), _size(0)
		{
			assign(first, last);
		}

		vector(const vector& v) : _base(NULL), _capacity(0), _size(0),  _alloc(allocator_type())
		{
			*this = v;
		}

		virtual ~vector()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_base + i);
			_alloc.deallocate(_base, _size);
		}

		vector	&operator=(const vector& v)
		{
			assign(v.begin(), v.end());
			return (*this);
		}

		// iterators
		iterator begin()
		{
			return (iterator(_base));
		}
		
		const_iterator begin() const
		{
			return (const_iterator(_base));
		}

		iterator end()
		{
			return (iterator(_base + _size));
		}
		
		const_iterator end() const
		{
			return (const_iterator(_base + _size));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(iterator(_base + _size - 1)));
		}
		
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(iterator(_base + _size - 1)));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(iterator(_base - 1)));
		}
		
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(iterator(_base - 1)));
		}


		// capacity
		size_type size() const
		{
			return (_size);
		}
		
		size_type max_size() const
		{
			return (_alloc.max_size());
		}

		void resize(size_type n, value_type val = value_type())
		{
			reserve(n);
			if (n > _size)
			{
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_base + i, val);
			}
			else
			{
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(_base + i);
			}
			_size = n;
		}

		size_type capacity() const
		{
			return (_capacity);
		}

		bool empty() const
		{
			return (_size == 0);
		}

		void	reserve(size_type n)
		{
			pointer	copy = _base;
			
			if (_capacity >= n)
				return ;
			_capacity = _closestPow2(n);	
			_base = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_base + i, *(copy + i));
		}

		// element access
		reference operator[](size_type n)
		{
			return (reference(*(_base + n)));
		}
		
		const_reference operator[](size_type n) const
		{
			return (const_reference(*(_base + n)));
		}

		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range(_msgOutOfRange(n).c_str());
			return (*(_base + n));
		}
		
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range(_msgOutOfRange(n).c_str());
			return (*(_base + n));
		}

		reference front()
		{
			return (*(_base));
		}
		
		const_reference front() const
		{
			return (*(_base));
		}
		
		reference back()
		{
			return (*(_base + _size - 1));
		}
		
		const_reference back() const
		{
			return (*(_base + _size - 1));
		}
		
		// modifiers
		template <class It>
  		void assign(It first, It last, typename ft::enable_if<!ft::is_integral<It>::value, It>::type* = 0)
		{
			size_type	len = 0;
			It			save = first;

			while (first != last)
			{
				first++;
				len++;
			}
			reserve(len);
			clear();
			while (save != last)
			{
				_alloc.construct(_base + _size, *save);
				_size++;
				save++;
			}
		}
		
		void assign(size_type n, const value_type& val)
		{
			reserve(n);
			clear();
			_size = n;
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_base + i, val);
		}

		void push_back(const value_type& val)
		{
			reserve(_size + 1);
			_alloc.construct(_base + _size, val);
			_size++;
		}
		
		void pop_back()
		{
			if (_size == 0)
				return;
			_alloc.destroy(_base + _size - 1);
			_size--;
		}

		iterator	insert(iterator position, const value_type& val)
		{
			size_type	offset = position - begin();

			insert(position, 1, val);
			return (iterator(_base + offset));
		}

		void	insert(iterator position, size_type n, const value_type& val)
		{
			size_type	offset = position - begin();
			vector		copy(begin() + offset, end());

			reserve(_size + n);
			_size += n;
			for (size_type i = 0; i < n; i++)
			{
				_alloc.destroy(_base + offset + i);
				_alloc.construct(_base + offset + i, val);
			}
			for (size_type i = 0; i < copy.size(); i++)
				_alloc.construct(_base + offset + n + i, copy[i]);
		}

		template <class It>
    	void	insert(iterator position, It first, It last, typename ft::enable_if<!ft::is_integral<It>::value, It>::type* = 0)
		{
			size_type	n = 0;
			size_type	offset = position - begin();
			vector		copy(begin() + offset, end());
			It			save = first;

			while (first != last)
			{
				first++;
				n++;
			}
			reserve(_size + n);
			_size += n;
			for (size_type i = 0; i < copy.size(); i++)
				_alloc.destroy(_base + offset + i);
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_base + offset + i, *save);
				save++;
			}
			for (size_type i = 0; i < copy.size(); i++)
				_alloc.construct(_base + offset + n + i, copy[i]);
		}
		
		iterator 	erase(iterator position)
		{
			return (erase(position, position + 1));
		}

		iterator	erase(iterator first, iterator last)
		{
			vector		copy(last, end());
			size_type	n = 0;
			size_type	toDelete = end() - first;
			size_type	toCopy = end() - last;
			iterator	save = first;

			while (first != last)
			{
				first++;
				n++;
			}
			_size -= n;
			for (size_type i = 0; i < toDelete; i++)
				_alloc.destroy(save.base() + i);
			for (size_type i = 0; i < toCopy; i++)
				_alloc.construct(save.base() + i, copy[i]);
			return (save);
		}

		void 		swap(vector& x)
		{
			pointer			base = _base;
			size_type		capacity = _capacity;
			size_type		size = _size;
			allocator_type	alloc = _alloc;

			_base = x._base;
			_capacity = x._capacity;
			_size = x._size;
			_alloc = x._alloc;

			x._base = base;
			x._capacity = capacity;
			x._size = size;
			x._alloc = alloc;
		}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_base + i);
			_size = 0;
		}

		// allocator
		allocator_type get_allocator() const
		{
			return (allocator_type());
		}
		
    };

	// Non-member function overloads

	template <class T>
	bool operator==(const vector<T>& v1, const vector<T>& v2)
	{
		if (v1.size() != v2.size())
			return (false);
		
		for (typename vector<T>::size_type i = 0; i < v1.size(); i++)
		{
			if (v1[i] != v2[i])
				return (false);
		}
		return (true);
	}

	template <class T>
	bool operator!=(const vector<T>& v1, const vector<T>& v2)
	{
		return (!(v1 == v2));
	}

	template <class T>
	bool operator<(const vector<T>& v1, const vector<T>& v2)
	{
		for (typename vector<T>::size_type i = 0; i < v1.size() && i < v2.size(); i++)
		{
			if (v2[i] < v1[i])
				return (false);
			if (v1[i] < v2[i])
				return (true);
		}
		return (v1.size() < v2.size());
	}

	template <class T>
	bool operator<=(const vector<T>& v1, const vector<T>& v2)
	{
		return (!(v2 < v1));
	}

	template <class T>
	bool operator>(const vector<T>& v1, const vector<T>& v2)
	{
		return (v2 < v1);
	}

	template <class T>
	bool operator>=(const vector<T>& v1, const vector<T>& v2)
	{

		return (!(v1 < v2));
	}

	template <class T>
	void swap(vector<T>& x, vector<T>& y)
	{
		x.swap(y);
	}
}

#endif
