/**
 ** \file ast/assign-exp.hxx
 ** \brief Inline methods of ast::AssignExp.
 */

#pragma once

#include <ast/assign-exp.hh>

namespace ast
{
  // DONE: Some code was deleted here.
  inline const Exp& AssignExp::exp_get() const { return *exp_; }
  inline Exp& AssignExp::exp_get() { return *exp_; }

  inline const Var& AssignExp::var_get() const { return *var_; }
  inline Var& AssignExp::var_get() { return *var_; }
} // namespace ast
