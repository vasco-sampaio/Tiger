/**
 ** \file ast/call-exp.hh
 ** \brief Declaration of ast::CallExp.
 */

#pragma once

#include <ast/exp.hh>
#include <ast/function-dec.hh>
#include <misc/symbol.hh>
#include "bindable.hh"

namespace ast
{
  /// CallExp.
  class CallExp : public Exp, public Bindable
  {
    // DONE: Some code was deleted here.
    public:
    
    CallExp(const Location& location, misc::symbol name,
            exps_type* args);
    CallExp(const CallExp&) = delete;
    CallExp& operator=(const CallExp&) = delete;
    
    ~CallExp() override;
   
    void accept(ConstVisitor& v) const override;
   
    void accept(Visitor& v) override;
    
    const misc::symbol& name_get() const;
 
    misc::symbol& name_get();
   
    const exps_type& args_get() const;
   
    exps_type& args_get();
   
  protected:
    
    misc::symbol name_;

    exps_type* args_;
  };
} // namespace ast
#include <ast/call-exp.hxx>
