/*
 */

#ifndef SQLPP11_DATA_TYPES_DECIMAL_PARAMETER_VALUE_H
#define SQLPP11_DATA_TYPES_DECIMAL_PARAMETER_VALUE_H

#include <sqlpp11/data_types/parameter_value.h>
#include <sqlpp11/data_types/parameter_value_base.h>
#include <sqlpp11/data_types/decimal/data_type.h>
#include <sqlpp11/data_types/decimal/wrap_operand.h>
#include <sqlpp11/data_types/decimal/operand.h>
#include <sqlpp11/tvin.h>

namespace sqlpp
{
  template <>
  struct parameter_value_t<decimal> : public parameter_value_base<decimal>
  {
    using base = parameter_value_base<decimal>;
    using base::base;
    using base::operator=;

    template <typename Target>
    void _bind(Target& target, size_t index) const
    {
      target._bind_decimal_parameter(index, &_value, _is_null);
    }
  };
}  // namespace sqlpp
#endif
