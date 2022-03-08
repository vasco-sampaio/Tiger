/**
 ** \file ast/if-exp.hh
 ** \brief Declaration of ast::IfExp.
 */

#pragma once

#include <ast/exp.hh>
#include <ast/seq-exp.hh>

namespace ast
{
  /// IfExp.
  class IfExp : public Exp
  {
    // DONE: Some code was deleted here.
    public:
    IfExp(const Location& location, Exp* test,
                                             Exp* thenclause,
                                             Exp* elseclause);

    IfExp(const Location& location, Exp* test, Exp* thenclause);
    IfExp(const IfExp&) = delete;
    IfExp& operator=(const IfExp&) = delete;
    ~IfExp() override;
    void accept(ConstVisitor& v) const override;
    void accept(Visitor& v) override;


    const Exp& test_get() const;
    Exp& test_get();
    const Exp& then_clause_get() const;
    Exp& then_clause_get();
    const Exp* else_clause_get() const;
    Exp* else_clause_get();

  protected:
    Exp* test_;
    Exp* thenclause_;
    Exp* elseclause_;
  };
} // namespace ast
#include <ast/if-exp.hxx>
