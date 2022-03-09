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
#include "dec.hh"

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
    ostr_ << ", ";
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

  void PrettyPrinter::operator()(const SeqExp& e)
  {
    for (auto& x : e.exps_get())
      {
        x->accept(*this);
        ostr_ << misc::iendl;
      }
  }

  void PrettyPrinter::operator()(const OpExp& e)
  {
    std::string op = "";
    switch (e.oper_get())
      {
      case OpExp::Oper::add:
        op = "+";
        break;
      case OpExp::Oper::sub:
        op = "-";
        break;
      case OpExp::Oper::mul:
        op = "*";
        break;
      case OpExp::Oper::div:
        op = "/";
        break;
      case OpExp::Oper::eq:
        op = "=";
        break;
      case OpExp::Oper::ne:
        op = "<>";
        break;
      case OpExp::Oper::lt:
        op = "<";
        break;
      case OpExp::Oper::le:
        op = ">=";
        break;
      case OpExp::Oper::gt:
        op = ">";
        break;
      case OpExp::Oper::ge:
        op = ">=";
        break;
      default:
        op = "+";
      }
    e.left_get().accept(*this);
    ostr_ << ' ' << op << ' ';
    e.right_get().accept(*this);
  }

  void PrettyPrinter::operator()(const CallExp& e)
  {
    ostr_ << e.name_get();
    ostr_ << " (";
    size_t size = e.args_get().size();
    size_t i = 0;
    for (auto k : e.args_get())
      {
        k->accept(*this);
        if (i != size - 1)
          ostr_ << ", ";
        i++;
      }
    ostr_ << ')';
  }

  void PrettyPrinter::operator()(const FunctionDec& e)
  {
    ostr_ << "function " << e.name_get() << " (" << misc::incindent;
    e.formals_get().accept(*this);

    ostr_ << ") : ";
    e.result_get()->accept(*this);
    ostr_ << " = ";
    e.body_get()->accept(*this);
    ostr_ << misc::decindent;
  }

  void PrettyPrinter::operator()(const NameTy& e) { ostr_ << e.name_get(); }

  void PrettyPrinter::operator()(const LetExp& e)
  {
    ostr_ << "let" << misc::incindent << misc::iendl;
    e.decs_get().accept(*this);
    ostr_ << misc::decindent << misc::iendl << "in " << misc::incindent;
    e.body_get().accept(*this);
    ostr_ << misc::decindent << misc::iendl << "end" << misc::iendl;
 }
  void PrettyPrinter::operator()(const VarChunk& e)
  {
    size_t size = e.decs_get().size();
    size_t i = 0;
    for (auto k : e.decs_get())
      {
        k->accept(*this);
        if (i != size - 1)
          ostr_ << ", ";
        i++;
      }
  }

  void PrettyPrinter::operator()(const VarDec& e)
  {
    ostr_ << e.name_get();
    ostr_ << " : ";
    e.type_name_get()->accept(*this);
    if (e.init_get())
    {
      ostr_ << " = ";
      e.init_get()->accept(*this);
    }
      
  }

} // namespace ast
