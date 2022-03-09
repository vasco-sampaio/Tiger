/**
 ** \file ast/pretty-printer.cc
 ** \brief Implementation of ast::PrettyPrinter.
 */

#include <cstddef>
#include <ast/all.hh>
#include <ast/libast.hh>
#include <ast/pretty-printer.hh>
#include <misc/escape.hh>
#include <misc/indent.hh>
#include <misc/separator.hh>

namespace ast
{
  // Anonymous namespace: these functions are private to this file.
  namespace
  {

    /// \brief Output \a e on \a ostr.
    ///
    /// Used to factor the output of the name declared,
    /// and its possible additional attributes.
    inline std::ostream& operator<<(std::ostream& ostr, const Dec& e)
    {
      ostr << e.name_get();
      return ostr;
    }
  } // namespace

  PrettyPrinter::PrettyPrinter(std::ostream& ostr)
    : ostr_(ostr)
  {}

  void PrettyPrinter::operator()(const SimpleVar& e) { e.name_get(); }

  /*void PrettyPrinter::operator()(const FieldVar& e)
  {
    // FIXME: Some code was deleted here.
  }*/

  /* Foo[10]. */
  void PrettyPrinter::operator()(const SubscriptVar& e)
  {
    ostr_ << e.var_get() << '[' << misc::incindent << e.index_get()
          << misc::decindent << ']';
  }

  void PrettyPrinter::operator()(const CastExp& e)
  {
    ostr_ << "_cast(";
    e.exp_get().accept(*this); 
    ostr_<< ", ";
    e.ty_get();
    ostr_ << ')';
  }

  // FIXME: Some code was deleted here.
  void PrettyPrinter::operator()(const IntExp& e) { ostr_ << e.value_get(); }

  void PrettyPrinter::operator()(const StringExp& e)
  {
    ostr_ << e.string_get();
  }

  void PrettyPrinter::operator()(const ObjectExp& e)
  {
    e.type_name_get().accept(*this);
    //ostr_ << e.type_name_get();
  }

  void PrettyPrinter::operator()(const IfExp& e)
  {
    ostr_ << "if" << '(';
    e.test_get().accept(*this);
    ostr_ << ')' << " then" << misc::iendl;
    e.then_clause_get().accept(*this);
    ostr_ << misc::decindent;
    if (e.else_clause_get() != nullptr)
      {
        ostr_ << misc::decindent << "else" << misc::iendl;
        e.else_clause_get()->accept(*this);
        ostr_ << misc::decindent;
      }
  }

  void PrettyPrinter::operator()(const WhileExp& e)
  {
    ostr_ << "while" << '(';
    e.test_get().accept(*this);
    ostr_ << ')' << " do" << misc::iendl;
    e.body_get().accept(*this);
    ostr_ << misc::decindent;
  }

  void PrettyPrinter::operator()(const ForExp& e)
  {
    ostr_ << "for";
    e.vardec_get().accept(*this);
    ostr_ << " to ";
    e.hi_get().accept(*this);
    ostr_ << " do " << misc::incindent;
    e.body_get().accept(*this);
    ostr_ << misc::decindent;
  }

  void PrettyPrinter::operator()(const NilExp& e) { ostr_ << "nil"; }

  void PrettyPrinter::operator()(const AssignExp& e)
  {
    e.var_get().accept(*this);
    ostr_ << " := ";
    e.exp_get().accept(*this);
  }

  void PrettyPrinter::operator()(const BreakExp& e) { ostr_ << "break"; }

} // namespace ast
