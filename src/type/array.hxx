/**
 ** \file type/array.hxx
 ** \brief Inline methods for type::Array.
 */
#pragma once

#include <misc/contract.hh>
#include <type/array.hh>

namespace type
{
  // DONE: Some code was deleted here.

  inline const Type& Array::elements_type_get() const
  {
    return elements_type_;
  }

} // namespace type
