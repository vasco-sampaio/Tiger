/**
 ** \file ast/escapable.hh
 ** \brief Declaration of ast::Escapable.
 */

#pragma once

#include <ast/fwd.hh>

namespace ast
{
  /// Escapable.
  class Escapable
  {
  // DONE: Some code was deleted here.
  public:
    bool escape_get();
    void escape_set(bool value);
    bool escape_get() const;
  private:
    bool escape_ = true;
  };
} // namespace ast
#include <ast/escapable.hxx>
