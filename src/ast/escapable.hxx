/**
 ** \file ast/escapable.hxx
 ** \brief Inline methods of ast::Escapable.
 */

#pragma once

#include <ast/escapable.hh>

namespace ast
{
  // DONE: Some code was deleted here.
  inline bool Escapable::escape_get()
  {
    return escape_;
  }

  inline bool Escapable::escape_get() const
  {
    return escape_;
  }
    
  inline void Escapable::escape_set(bool value)
  {
    escape_ = value;
  }
} // namespace ast
