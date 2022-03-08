/**
 ** \file ast/call-exp.hxx
 ** \brief Inline methods of ast::CallExp.
 */

#pragma once

#include <ast/call-exp.hh>

namespace ast
{
  // DONE: Some code was deleted here.
  inline const misc::symbol& CallExp::name_get() const { return name_; }
 
  inline misc::symbol& CallExp::name_get() { return name_; }
   
  inline const exps_type& CallExp::args_get() const { return *args_; }
   
  inline exps_type& CallExp::args_get() { return *args_; }
} // namespace ast
