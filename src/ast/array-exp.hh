/**
 ** \file ast/array-exp.hh
 ** \brief Declaration of ast::ArrayExp.
 */

#pragma once

#include <ast/exp.hh>
#include <ast/name-ty.hh>

namespace ast
{
  /// ArrayExp.
  class ArrayExp : public Exp
  {
    // DONE: Some code was deleted here.
    public:
    ArrayExp(const Location& location, NameTy* type_name, Exp* size,
                                      Exp* init);
    ArrayExp(const ArrayExp&) = delete;
    ArrayExp& operator=(const ArrayExp&) = delete;

    ~ArrayExp() override;

    void accept(ConstVisitor& v) const override;

    void accept(Visitor& v) override;


    const NameTy& type_name_get() const;

    NameTy& type_name_get();

    const Exp& size_get() const;

    Exp& size_get();

    const Exp& init_get() const;

    Exp& init_get();

    protected:
    NameTy* type_name_;
    Exp* size_;
    Exp* init_;
  };
} // namespace ast
#include <ast/array-exp.hxx>
