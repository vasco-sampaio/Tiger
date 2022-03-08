/**
 ** \file ast/object-exp.hh
 ** \brief Declaration of ast::ObjectExp.
 */

#pragma once

#include <ast/exp.hh>
#include <ast/name-ty.hh>

namespace ast
{
  /// ObjectExp.
  class ObjectExp : public Exp
  {
    // DONE: Some code was deleted here.
  public:
    ObjectExp(const Location& location, NameTy* type_name);
    ObjectExp(const ObjectExp&) = delete;
    ObjectExp& operator=(const ObjectExp&) = delete;
    ~ObjectExp() override;
    void accept(ConstVisitor& v) const override;
    void accept(Visitor& v) override;


    const NameTy& type_name_get() const;
    NameTy& type_name_get();

  protected:
    NameTy* type_name_;
  };
} // namespace ast
#include <ast/object-exp.hxx>
