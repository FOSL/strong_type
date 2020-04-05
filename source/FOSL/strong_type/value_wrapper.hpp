#ifndef _FOSL_STRONG_TYPE_VALUE_WRAPPER_HPP_
#define _FOSL_STRONG_TYPE_VALUE_WRAPPER_HPP_

#include <utility>

#include <FOSL/metaprogramming.hpp>

namespace FOSL::strong_type
{
	using namespace metaprogramming;

	template <typename _value_type, typename = requires<>>
	struct value_wrapper
	{
	public:
		using value_type = _value_type;

	public:
		value_wrapper(void) { }
		value_wrapper(value_wrapper<value_type> const&  other) : value(          other.value ) { }
		value_wrapper(value_wrapper<value_type>      && other) : value(std::move(other.value)) { }
		value_wrapper(value_type value) : value(std::move(value)) { }
	private: // VARIABLES
		value_type value;

	public:
		operator value_type      &(void) { return value; }
		operator value_type const&(void) { return value; }
		value_wrapper<value_type>& operator =(value_wrapper<value_type> const&  other) { value =           other.value ; return *this; }
		value_wrapper<value_type>& operator =(value_wrapper<value_type>      && other) { value = std::move(other.value); return *this; }

	template <typename value_type>
	friend auto value(value_wrapper<value_type>&) -> value_type&;
	template <typename value_type>
	friend auto value(const value_wrapper<value_type>&) -> const value_type&;
	};

	template <typename _value_type>
	struct value_wrapper<_value_type, requires<enable_if<is_not_trivial<_value_type>>> : _value_type;
	{
	};

	template <typename type> auto
	value(type& instance) -> type&
	{ return instance; }
	template <typename value_type> auto
	value(value_wrapper<value_type>& instance)
		-> value_type& { return instance.value; }
	template <typename value_type> auto
	value(const value_wrapper<value_type>& instance)
		-> const value_type& { return instance.value; }

// 	template <typename value_type> auto
// 	operator =(       value_type& lhs
//               , const value_type& rhs )
// 		-> value_type&
// 	{
// 		value(lhs) = value(rhs);
// 		return lhs;
// 	}
	template <typename value_type> auto
	operator ==( const value_wrapper<value_type>& lhs
	           , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) == value(rhs); }

	template <typename value_type> auto
	operator ==( const value_wrapper<value_type>& lhs
	           , const               value_type & rhs )
		-> bool { return value(lhs) == value(rhs); }

	template <typename value_type> auto
	operator ==( const               value_type & lhs
	           , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) == value(rhs); }

	template <typename value_type> auto
	operator !=( const value_wrapper<value_type>& lhs
	           , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) != value(rhs); }

	template <typename value_type> auto
	operator !=( const value_wrapper<value_type>& lhs
	           , const               value_type & rhs )
		-> bool { return value(lhs) != value(rhs); }

	template <typename value_type> auto
	operator !=( const               value_type & lhs
	           , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) != value(rhs); }

	template <typename value_type> auto
	operator >( const value_wrapper<value_type>& lhs
              , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) > value(rhs); }

	template <typename value_type> auto
	operator >( const value_wrapper<value_type>& lhs
              , const               value_type & rhs )
		-> bool { return value(lhs) > value(rhs); }

	template <typename value_type> auto
	operator >( const               value_type & lhs
              , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) > value(rhs); }

	template <typename value_type> auto
	operator <( const value_wrapper<value_type>& lhs
              , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) < value(rhs); }

	template <typename value_type> auto
	operator <( const value_wrapper<value_type>& lhs
              , const               value_type & rhs )
		-> bool { return value(lhs) < value(rhs); }

	template <typename value_type> auto
	operator <( const               value_type & lhs
              , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) < value(rhs); }

	template <typename value_type> auto
	operator >=( const value_wrapper<value_type>& lhs
	           , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) >= value(rhs); }

	template <typename value_type> auto
	operator >=( const value_wrapper<value_type>& lhs
               , const               value_type & rhs )
		-> bool { return value(lhs) >= value(rhs); }

	template <typename value_type> auto
	operator >=( const               value_type & lhs
               , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) >= value(rhs); }

	template <typename value_type> auto
	operator <=( const value_wrapper<value_type>& lhs
               , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) <= value(rhs); }

	template <typename value_type> auto
	operator <=( const value_wrapper<value_type>& lhs
               , const               value_type & rhs )
		-> bool { return value(lhs) <= value(rhs); }

	template <typename value_type> auto
	operator <=( const               value_type & lhs
               , const value_wrapper<value_type>& rhs )
		-> bool { return value(lhs) <= value(rhs); }

	template <typename value_type> auto
	operator +( const value_wrapper<value_type>& lhs
              , const value_wrapper<value_type>& rhs )
		-> value_type { return value(lhs) + value(rhs); }

	template <typename value_type> auto
	operator +( const value_wrapper<value_type>& lhs
              , const               value_type & rhs )
		-> value_type { return value(lhs) + value(rhs); }

	template <typename value_type> auto
	operator +( const               value_type & lhs
              , const value_wrapper<value_type>& rhs )
		-> value_type { return value(lhs) + value(rhs); }

	template <typename value_type> auto
	operator -( const value_wrapper<value_type>& lhs
              , const value_wrapper<value_type>& rhs )
		-> value_type { return value(lhs) - value(rhs); }

	template <typename value_type> auto
	operator -( const value_wrapper<value_type>& lhs
              , const               value_type & rhs )
		-> value_type { return value(lhs) - value(rhs); }

	template <typename value_type> auto
	operator -( const               value_type & lhs
              , const value_wrapper<value_type>& rhs )
		-> value_type { return value(lhs) - value(rhs); }

	template <typename value_type> auto
	operator *( const value_wrapper<value_type>& lhs
              , const value_wrapper<value_type>& rhs )
		-> value_type { return value(lhs) * value(rhs); }

	template <typename value_type> auto
	operator *( const value_wrapper<value_type>& lhs
              , const               value_type & rhs )
		-> value_type { return value(lhs) * value(rhs); }

	template <typename value_type> auto
	operator *( const               value_type & lhs
              , const value_wrapper<value_type>& rhs )
		-> value_type { return value(lhs) * value(rhs); }

	template <typename value_type> auto
	operator /( const value_wrapper<value_type>& lhs
              , const value_wrapper<value_type>& rhs )
		-> value_type { return value(lhs) / value(rhs); }

	template <typename value_type> auto
	operator /( const value_wrapper<value_type>& lhs
              , const               value_type & rhs )
		-> value_type { return value(lhs) / value(rhs); }

	template <typename value_type> auto
	operator /( const               value_type & lhs
              , const value_wrapper<value_type>& rhs )
		-> value_type { return value(lhs) / value(rhs); }

	template <typename value_type> auto
	operator ++(value_wrapper<value_type>& operand)
		-> value_type&
	{
		++value(operand);
		return operand;
	}
	template <typename value_type> auto
	operator --(value_wrapper<value_type>& operand)
		-> value_type&
	{
		--value(operand);
		return operand;
	}
	template <typename value_type> auto
	operator ++(value_wrapper<value_type>& operand, int)
		-> decltype(value(value_type{}))
	{
		value_type result = operand;
		value(operand)++;
		return result;
	}
	template <typename value_type> auto
	operator --(value_wrapper<value_type>& operand, int)
		-> decltype(value(value_type{}))
	{
		value_type result = operand;
		value(operand)--;
		return result;
	}
}

#endif
