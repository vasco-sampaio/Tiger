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

  void PrettyPrinter::operator()(const SimpleVar& e) { ostr_ << e.name_get(); }

  void PrettyPrinter::operator()(const FieldVar& e)
  {
    // FIXME: Some code was deleted here.
  }

  /* Foo[10]. */
  void PrettyPrinter::operator()(const SubscriptVar& e)
  {
    ostr_ << e.var_get() << '[' << misc::incindent << e.index_get()
          << misc::decindent << ']';
  }

  void PrettyPrinter::operator()(const CastExp& e)
  {
    ostr_ << "_cast(" << e.exp_get() << ", " << e.ty_get() << ')';
  }

  // FIXME: Some code was deleted here.
  void PrettyPrinter::operator()(const IntExp& e) { ostr_ << e.value_get(); }

  void PrettyPrinter::operator()(const StringExp& e)
  {
    ostr_ << e.string_get();
  }

  void PrettyPrinter::operator()(const ObjectExp& e)
  {
    ostr_ << e.type_name_get();
  }

  void PrettyPrinter::operator()(const CallExp& e)
  {
    ostr_ << e.name_get() << '(';
    auto begin = e.args_get().begin();
    ostr_ << *begin;
    while (begin != e.args_get().end())
      {
        ostr_ << ',' << *begin;
        begin++;
      }
    ostr_ << ')';
  }

  void PrettyPrinter::operator()(const IfExp& e)
  {
    ostr_ << "if" << '(' << e.test_get() << ')' << " then" << misc::iendl
          << e.then_clause_get() << misc::decindent;
    if (e.else_clause_get() != nullptr)
      {
        ostr_ << misc::decindent << "else" << misc::iendl
              << *(e.else_clause_get()) << misc::decindent;
      }
  }

  void PrettyPrinter::operator()(const WhileExp& e)
  {
    ostr_ << "while" << '(' << e.test_get() << ')' << " do" << misc::iendl
          << e.body_get() << misc::decindent;
  }
} // namespace ast
