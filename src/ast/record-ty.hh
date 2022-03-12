/**
 ** \file ast/record-ty.hh
 ** \brief Declaration of ast::RecordTy.
 */

#pragma once

#include <ast/field.hh>
#include <ast/ty.hh>

namespace ast
{
  /// RecordTy.
  class RecordTy : public Ty
  {
    // DONE: Some code was deleted here.
  public:
    RecordTy(const Location& location, fields_type* fields);
    RecordTy(const RecordTy&) = delete;
    RecordTy& operator=(const RecordTy&) = delete;
    ~RecordTy() override;
    void accept(ConstVisitor& v) const override;
    void accept(Visitor& v) override;

    const fields_type& fields_get() const;
    fields_type& fields_get();

  protected:
    fields_type* fields_;
  };
} // namespace ast
#include <ast/record-ty.hxx>
