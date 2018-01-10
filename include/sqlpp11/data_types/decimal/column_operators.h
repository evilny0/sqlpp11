/*
 */

#ifndef SQLPP11_DATA_TYPES_DECIMAL_COLUMN_OPERATORS_H
#define SQLPP11_DATA_TYPES_DECIMAL_COLUMN_OPERATORS_H

#include <sqlpp11/type_traits.h>
#include <sqlpp11/assignment.h>
#include <sqlpp11/data_types/decimal/data_type.h>
#include <sqlpp11/data_types/column_operators.h>

namespace sqlpp
{
  template <typename Column>
  struct column_operators<Column, decimal>
  {
    template <typename T>
    using _is_valid_operand = is_valid_operand<decimal, T>;

    template <typename T>
    auto operator+=(T t) const -> assignment_t<Column, plus_t<Column, decimal, wrap_operand_t<T>>>
    {
      using rhs = wrap_operand_t<T>;
      static_assert(_is_valid_operand<rhs>::value, "invalid rhs assignment operand");

      return {*static_cast<const Column*>(this), {*static_cast<const Column*>(this), rhs{t}}};
    }

    template <typename T>
    auto operator-=(T t) const -> assignment_t<Column, minus_t<Column, decimal, wrap_operand_t<T>>>
    {
      using rhs = wrap_operand_t<T>;
      static_assert(_is_valid_operand<rhs>::value, "invalid rhs assignment operand");

      return {*static_cast<const Column*>(this), {*static_cast<const Column*>(this), rhs{t}}};
    }

    template <typename T>
    auto operator/=(T t) const -> assignment_t<Column, divides_t<Column, wrap_operand_t<T>>>
    {
      using rhs = wrap_operand_t<T>;
      static_assert(_is_valid_operand<rhs>::value, "invalid rhs assignment operand");

      return {*static_cast<const Column*>(this), {*static_cast<const Column*>(this), rhs{t}}};
    }

    template <typename T>
    auto operator*=(T t) const -> assignment_t<Column, multiplies_t<Column, decimal, wrap_operand_t<T>>>
    {
      using rhs = wrap_operand_t<T>;
      static_assert(_is_valid_operand<rhs>::value, "invalid rhs assignment operand");

      return {*static_cast<const Column*>(this), {*static_cast<const Column*>(this), rhs{t}}};
    }
  };
}  // namespace sqlpp
#endif
