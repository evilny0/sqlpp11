/*
 */

#ifndef SQLPP11_DATA_TYPES_DECIMAL_WRAP_OPERAND_H
#define SQLPP11_DATA_TYPES_DECIMAL_WRAP_OPERAND_H

#include <utility>
#include <sqlpp11/wrap_operand.h>
#include <boost/multiprecision/gmp.hpp>

namespace sqlpp
{
  struct decimal_operand;

  template <typename T>
  struct wrap_operand<T, typename std::enable_if<std::is_same<boost::multiprecision::mpf_float_50, T>::value>::type>
  {
    using type = decimal_operand;
  };
}  // namespace sqlpp
#endif
