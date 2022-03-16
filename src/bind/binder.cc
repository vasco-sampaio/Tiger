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
    // DONE: Some code was deleted here.
    func_map_.scope_begin();
    var_map_.scope_begin();
    type_map_.scope_begin();
  }

  void Binder::scope_end()
  {
    // DONE: Some code was deleted here.
    func_map_.scope_end();
    var_map_.scope_end();
    type_map_.scope_end();
  }

  /*---------.
  | Visits.  |
  `---------*/

  // FIXME: Some code was deleted here.

  void Binder::operator()(ast::ChunkList& e)
  {
    for (auto& x : e)
    {
      x->accept(*this);
    }
  }

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
    // manage error in case of mutliple declaration with this var's name
    func_map_.put(e.name_get(), &e);
    e.formals_get().accept(*this);
    if (e.result_get() != nullptr)
      e.result_get()->accept(*this);
    e.body_get()->accept(*this);
    this->scope_end();
  }

  void Binder::operator()(ast::VarDec& e)
  {
    this->scope_begin();
    // manage error in case of mutliple declaration with this var's name
    var_map_.put(e.name_get(), &e);
    this->accept(e.init_get());
    this->scope_end();
  }
  void Binder::operator()(ast::TypeDec& e)
  {
    this->scope_begin();
    type_map_.put(e.name_get(), &e);
    e.ty_get().accept(*this);
    this->scope_end();
  }
  // void Binder::operator()(ast::MethodDec& e)
  // void Binder::operator()(ast::WhileExp& e)
  // void Binder::operator()(ast::ForExp& e)

  /*-------------------.
  | Visiting VarChunk. |
  `-------------------*/

  // FIXME: Some code was deleted here.
  //void Binder::operator()(ast::VarChunk& e)

  /*------------------------.
  | Visiting FunctionChunk. |
  `------------------------*/

  // FIXME: Some code was deleted here.
  //void Binder::operator()(ast::FunctionChunk& e)

  /*--------------------.
  | Visiting TypeChunk. |
  `--------------------*/
  // FIXME: Some code was deleted here.
  //void Binder::operator()(ast::TypeChunk& e)

} // namespace bind
