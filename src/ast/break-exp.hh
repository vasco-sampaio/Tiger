/**
 ** \file ast/break-exp.hh
 ** \brief Declaration of ast::BreakExp.
 */

#pragma once

#include <ast/exp.hh>

namespace ast
{
  /// BreakExp.
  class BreakExp : public Exp
  {
     // DONE: Some code was deleted here.
    public:
    
    BreakExp(const Location& location);
    BreakExp(const BreakExp&) = delete;
    BreakExp& operator=(const BreakExp&) = delete;
    
    // ~BreakExp() override;
   
    void accept(ConstVisitor& v) const override;
   
    void accept(Visitor& v) override;
  };
} // namespace ast
#include <ast/break-exp.hxx>
