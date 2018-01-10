/*
 */

#ifndef SQLPP11_DATA_TYPES_DECIMAL_EXPRESSION_OPERATORS_H
#define SQLPP11_DATA_TYPES_DECIMAL_EXPRESSION_OPERATORS_H

#include <sqlpp11/expression_return_types.h>
#include <sqlpp11/operand_check.h>
#include <sqlpp11/expression_operators.h>
#include <sqlpp11/basic_expression_operators.h>
#include <sqlpp11/type_traits.h>
#include <sqlpp11/data_types/decimal/data_type.h>

namespace sqlpp
{
  template <typename Expr>
  struct expression_operators<Expr, decimal> : public basic_expression_operators<Expr>
  {
  };

  template <typename L, typename R>
  struct return_type_plus<L, R, binary_operand_check_t<L, is_decimal_t, R, is_numeric_t>>
  {
    using check = consistent_t;
    using type = plus_t<wrap_operand_t<L>, decimal, wrap_operand_t<R>>;
  };

  template <typename L, typename R>
  struct return_type_minus<L, R, binary_operand_check_t<L, is_decimal_t, R, is_numeric_t>>
  {
    using check = consistent_t;
    using type = minus_t<wrap_operand_t<L>, decimal, wrap_operand_t<R>>;
  };

  template <typename L, typename R>
  struct return_type_multiplies<L, R, binary_operand_check_t<L, is_decimal_t, R, is_numeric_t>>
  {
    using check = consistent_t;
    using type = multiplies_t<wrap_operand_t<L>, decimal, wrap_operand_t<R>>;
  };

  template <typename L, typename R>
  struct return_type_divides<L, R, binary_operand_check_t<L, is_decimal_t, R, is_numeric_t>>
  {
    using check = consistent_t;
    using type = divides_t<wrap_operand_t<L>, wrap_operand_t<R>>;
  };

  template <typename T, typename Defer>
  struct return_type_unary_plus<T, Defer, unary_operand_check_t<T, is_decimal_t>>
  {
    using check = consistent_t;
    using type = unary_plus_t<decimal, wrap_operand_t<T>>;
  };

  template <typename T, typename Defer>
  struct return_type_unary_minus<T, Defer, unary_operand_check_t<T, is_decimal_t>>
  {
    using check = consistent_t;
    using type = unary_minus_t<decimal, wrap_operand_t<T>>;
  };
}  // namespace sqlpp
#endif
