/**
 ** \file bind/renamer.cc
 ** \brief Implementation of bind::Renamer.
 */

#include <stdexcept>
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
    visit(e, new_names_.find(&e)->first);
    super_type::operator()(e);
  }

  void Renamer::operator()(ast::VarDec& e)
  {
    new_names_.insert(std::pair<const ast::Dec*, misc::symbol>(&e, new_name_compute(e)));
    visit(e, new_names_.find(&e)->first);
    super_type::operator()(e);
  }

  void Renamer::operator()(ast::TypeDec& e)
  { 
    new_names_.insert(std::pair<const ast::Dec*, misc::symbol>(&e, new_name_compute(e)));
    visit(e, new_names_.find(&e)->first);
    super_type::operator()(e);
  }

  void Renamer::operator()(ast::CallExp& e) 
  {
    visit(*(e.def_get()), new_names_.find(e.def_get())->first);
    super_type::operator()(e);
  }

  void Renamer::operator()(ast::ChunkList& e)
  {
    for (auto &x : e)
    {
      x->accept(*this);
    }
  }

} // namespace bind
