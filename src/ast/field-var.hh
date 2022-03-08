/**
 ** \file ast/field-var.hh
 ** \brief Declaration of ast::FieldVar.
 */

#pragma once

#include <ast/var.hh>
#include <misc/symbol.hh>

namespace ast
{
  /// FieldVar.
  class FieldVar : public Var
  {
    // DONE: Some code was deleted here.
    public:
    /** \name Ctor & dtor.
     ** \{ */
    /// Construct a SubscriptVar node.
    FieldVar(const Location& location, Var* var, misc::symbol name);
    FieldVar(const FieldVar&) = delete;
    FieldVar& operator=(const FieldVar&) = delete;
    /// Destroy a SubscriptVar node.
    ~FieldVar() override;
    /** \} */

    /// \name Visitors entry point.
    /// \{ */
    /// Accept a const visitor \a v.
    void accept(ConstVisitor& v) const override;
    /// Accept a non-const visitor \a v.
    void accept(Visitor& v) override;
    /// \}

    /** \name Accessors.
     ** \{ */
    /// Return the mother variable.
    const Var& var_get() const;
    /// Return the mother variable.
    Var& var_get();
    /// Return the offset expression.
    const misc::symbol& name_get() const;
    /// Return the offset expression.
    misc::symbol& name_get();
    /** \} */

  protected:
    /// The mother variable.
    Var* var_;
    /// The offset expression.
    misc::symbol name_;
  };
} // namespace ast
#include <ast/field-var.hxx>
