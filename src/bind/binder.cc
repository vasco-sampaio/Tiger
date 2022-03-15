/**
 ** \file bind/binder.cc
 ** \brief Implementation for bind/binder.hh.
 */

#include <ast/all.hh>
#include <bind/binder.hh>

#include <misc/contract.hh>

namespace bind
{
  /*-----------------.
  | Error handling.  |
  `-----------------*/

  /// The error handler.
  const misc::error& Binder::error_get() const { return error_; }

  // FIXME: Some code was deleted here (Error reporting).

  void Binder::check_main(const ast::FunctionDec& e)
  {
    // FIXME: Some code was deleted here.
  }

  /*----------------.
  | Symbol tables.  |
  `----------------*/

  void Binder::scope_begin()
  {
    // Done: Some code was deleted here.
    sc_map_.scope_begin();
  }

  void Binder::scope_end()
  {
    // Done: Some code was deleted here.
    sc_map_.scope_end();
  }

  /*---------.
  | Visits.  |
  `---------*/

  // FIXME: Some code was deleted here.

  void Binder::operator()(ast::LetExp& e)
  {
    this->scope_begin();
    e.decs_get()->accept(*this);
    if (e.body_get() != nullptr)
      e.body_get()->accept(*this);
    this->scope_end();
  }

  void Binder::operator()(ast::FunctionDec& e) 
  {
    this->scope_begin();
    e.formals_get().accept(*this);
    e.result_get()->accept(*this);
    e.body_get()->accept(*this);
    this->scope_end();
  }

  void Binder::operator()(ast::VarDec& e)
  void Binder::operator()(ast::TypeDec& e)
  void Binder::operator()(ast::MethodDec& e)
  void Binder::operator()(ast::WhileExp& e)
  void Binder::operator()(ast::ForExp& e)

  /*-------------------.
  | Visiting VarChunk. |
  `-------------------*/

  // FIXME: Some code was deleted here.
  void Binder::operator()(ast::VarChunk& e)

  /*------------------------.
  | Visiting FunctionChunk. |
  `------------------------*/

  // FIXME: Some code was deleted here.
  void Binder::operator()(ast::FunctionChunk& e)

  /*--------------------.
  | Visiting TypeChunk. |
  `--------------------*/
  // FIXME: Some code was deleted here.
  void Binder::operator()(ast::TypeChunk& e)

} // namespace bind
