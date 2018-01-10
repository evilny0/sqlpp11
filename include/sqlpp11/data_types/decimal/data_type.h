/*
 */

#ifndef SQLPP11_DATA_TYPES_DECIMAL_DATA_TYPE_H
#define SQLPP11_DATA_TYPES_DECIMAL_DATA_TYPE_H

#include <sqlpp11/type_traits.h>
#include <boost/multiprecision/gmp.hpp>

namespace sqlpp
{
  struct decimal
  {
    using _traits = make_traits<decimal, tag::is_value_type>;
    using _cpp_value_type = boost::multiprecision::mpf_float_50;

    template <typename T>
    using _is_valid_operand = is_decimal_t<T>;
  };
}  // namespace sqlpp
#endif
