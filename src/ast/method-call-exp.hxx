/**
 ** \file ast/method-call-exp.hxx
 ** \brief Inline methods of ast::MethodCallExp.
 */

#pragma once

#include <ast/method-call-exp.hh>

namespace ast
{
  // DONE: Some code was deleted here.
  inline const Var& MethodCallExp::object_get() const { return *object_; }

  inline Var& MethodCallExp::object_get() { return *object_; }
} // namespace ast
