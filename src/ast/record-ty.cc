/**
 ** \file ast/record-ty.cc
 ** \brief Implementation of ast::RecordTy.
 */

#include <ast/record-ty.hh>
#include <ast/visitor.hh>
#include <misc/algorithm.hh>

namespace ast
{
  // DONE: Some code was deleted here.
  RecordTy::RecordTy(const Location& location, fields_type* fields)
    : Ty(location)
    , fields_(fields)
  {}

  RecordTy::~RecordTy()
  {
    delete fields_;
  }

  void RecordTy::accept(ConstVisitor& v) const { v(*this); }

  void RecordTy::accept(Visitor& v) { v(*this); }
} // namespace ast
