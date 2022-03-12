/**
 ** \file ast/string-exp.cc
 ** \brief Implementation of ast::StringExp.
 */

#include <ast/string-exp.hh>
#include <ast/visitor.hh>

namespace ast
{
  // DONE: Some code was deleted here.
  StringExp::StringExp(const Location& location, std::string string)
    : Exp(location)
    , string_(string)
  {}

  void StringExp::accept(ConstVisitor& v) const { v(*this); }

  void StringExp::accept(Visitor& v) { v(*this); }
} // namespace ast
