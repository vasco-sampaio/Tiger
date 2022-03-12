/**
 ** \file ast/seq-exp.cc
 ** \brief Implementation of ast::SeqExp.
 */

#include <ast/seq-exp.hh>
#include <ast/visitor.hh>
#include <misc/algorithm.hh>

namespace ast
{
  // DONE: Some code was deleted here.
  SeqExp::SeqExp(const Location& location, exps_type* exps)
    : Exp(location)
    , exps_(exps)
  {}

  SeqExp::~SeqExp()
  {
    delete exps_;
  }

  void SeqExp::accept(ConstVisitor& v) const { v(*this); }

  void SeqExp::accept(Visitor& v) { v(*this); }
} // namespace ast
