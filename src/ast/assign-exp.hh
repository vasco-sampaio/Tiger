/**
 ** \file ast/assign-exp.hh
 ** \brief Declaration of ast::AssignExp.
 */

#pragma once

#include <ast/exp.hh>
#include <ast/var.hh>

namespace ast
{
  /// AssignExp.
  class AssignExp : public Exp
  {
    // DONE: Some code was deleted here.
    public:
    
    AssignExp(const Location& location, Var* var, Exp* exp);
    AssignExp(const AssignExp&) = delete;
    AssignExp& operator=(const AssignExp&) = delete;
    
    ~AssignExp() override;
   
    void accept(ConstVisitor& v) const override;
   
    void accept(Visitor& v) override;
    
    const Exp& exp_get() const;
 
    Exp& exp_get();
   
    const Var& var_get() const;
   
    Var& var_get();
   
  protected:
    
    Var* var_;

    Exp* exp_;
  };
} // namespace ast
#include <ast/assign-exp.hxx>
