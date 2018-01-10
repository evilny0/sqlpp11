/*
 */

#ifndef SQLPP11_DATA_TYPES_DECIMAL_RESULT_FIELD_H
#define SQLPP11_DATA_TYPES_DECIMAL_RESULT_FIELD_H

#include <sqlpp11/exception.h>
#include <sqlpp11/result_field.h>
#include <sqlpp11/result_field_base.h>
#include <sqlpp11/type_traits.h>
#include <sqlpp11/data_types/decimal/data_type.h>
#include <sqlpp11/field_spec.h>

namespace sqlpp
{
  template <typename Db, typename NameType, bool CanBeNull, bool NullIsTrivialValue>
  struct result_field_t<Db, field_spec_t<NameType, decimal, CanBeNull, NullIsTrivialValue>>
      : public result_field_base<Db, field_spec_t<NameType, decimal, CanBeNull, NullIsTrivialValue>>
  {
    template <typename Target>
    void _bind(Target& target, size_t index)
    {
      target._bind_decimal_result(index, &this->_value, &this->_is_null);
    }

    template <typename Target>
    void _post_bind(Target& target, size_t index)
    {
      target._post_bind_decimal_result(index, &this->_value, &this->_is_null);
    }
  };
}  // namespace sqlpp
#endif
