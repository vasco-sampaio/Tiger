/**
 ** \file type/type.hxx
 ** \brief Inline methods for type::Type.
 */
#pragma once

#include <misc/contract.hh>
#include <type/type.hh>

namespace type
{
  inline bool operator==(const Type& lhs, const Type& rhs)
  {
    // DONE: Some code was deleted here.
    return &lhs == &rhs;
  }

  inline bool operator!=(const Type& lhs, const Type& rhs)
  {
    // DONE: Some code was deleted here.
    return !lhs.compatible_with(rhs);
  }

} // namespace type
