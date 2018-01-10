/*
 */

#ifndef SQLPP11_DATA_TYPES_DECIMAL_OPERAND_H
#define SQLPP11_DATA_TYPES_DECIMAL_OPERAND_H

#include <sqlpp11/type_traits.h>
#include <sqlpp11/alias_operators.h>
#include <sqlpp11/serializer.h>

namespace sqlpp
{
  struct decimal_operand : public alias_operators<decimal_operand>
  {
    using _traits = make_traits<decimal, tag::is_expression, tag::is_wrapped_value>;
    using _nodes = detail::type_vector<>;
    using _is_aggregate_expression = std::true_type;

    using _value_t = boost::multiprecision::mpf_float_50;

    decimal_operand() : _t{}
    {
    }

    decimal_operand(_value_t t) : _t(t)
    {
    }

    decimal_operand(const decimal_operand&) = default;
    decimal_operand(decimal_operand&&) = default;
    decimal_operand& operator=(const decimal_operand&) = default;
    decimal_operand& operator=(decimal_operand&&) = default;
    ~decimal_operand() = default;

    bool _is_trivial() const
    {
      return _t == 0;
    }

    _value_t _t;
  };

  template <typename Context>
  struct serializer_t<Context, decimal_operand>
  {
    using _serialize_check = consistent_t;
    using Operand = decimal_operand;

    static Context& _(const Operand& t, Context& context)
    {
      context << std::setprecision(50) << std::fixed << t._t;
      //context << t._t;
      return context;
    }
  };
}  // namespace sqlpp
#endif
