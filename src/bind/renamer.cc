/**
 ** \file bind/renamer.cc
 ** \brief Implementation of bind::Renamer.
 */

#include <bind/renamer.hh>

namespace bind
{
  using namespace ast;

  Renamer::Renamer()
    : super_type()
    , new_names_()
  {}

  // DONE: Some code was deleted here.

  void Renamer::operator()(ast::FunctionDec& e)
  {
    if (e.name_get() == "_main" || e.body_get() == nullptr)
      return;
    new_names_.insert(std::pair<const ast::Dec*, misc::symbol>(&e, new_name_compute<const ast::FunctionDec&>(e)));
    e.formals_get().accept(*this);
    if (e.result_get() != nullptr)
      e.result_get()->accept(*this);
    if (e.body_get() != nullptr)
      e.body_get()->accept(*this);
  }

  void Renamer::operator()(ast::VarDec& e)
  {
    new_names_.insert(std::pair<const ast::Dec*, misc::symbol>(&e, new_name_compute(e)));
    if (e.type_name_get() != nullptr)
      e.type_name_get()->accept(*this);
    if (e.init_get())
      e.init_get()->accept(*this);
  }

  void Renamer::operator()(ast::TypeDec& e)
  { 
    new_names_.insert(std::pair<const ast::Dec*, misc::symbol>(&e, new_name_compute(e)));
    e.ty_get().accept(*this);
  }

} // namespace bind
