# include "enable_if.hpp"
# include <iostream>

template<typename T>
class Simple
{
	protected:
		T	_value;

	public:
		Simple(void) : _value(T()) { }
		Simple(const T &value) : _value(value) { }
//		Simple(const Simple &simple) : _value(simple._value) { }

		template<typename U>
		Simple(const Simple< U > &simple, typename ft::enable_if< (ft::are_const_same<T, U>::value), T>::type* = 0) :
		_value(simple.getValue()) { }

		void	show(void) const
		{
			std::cout << _value << std::endl;
		}

		const T	getValue(void) const
		{
			return (_value);
		}
};