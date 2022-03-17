/**
 ** \file bind/binder.hxx
 ** \brief Inline methods of bind::Binder.
 **/

#pragma once

#include <stdexcept>
#include <bind/binder.hh>

namespace bind
{
  /*-----------------.
  | Error handling.  |
  `-----------------*/

  // FIXME: Some code was deleted here (Error reporting).

  /*----------------------------.
  | Visiting /ChunkInterface/.  |
  `----------------------------*/

  template <class D> void Binder::chunk_visit(ast::Chunk<D>& e)
  {
    // Shorthand.
    // using chunk_type = ast::Chunk<D>; useless ?

    // DONE: Some code was deleted here (Two passes: once on headers, then on bodies).
    int tmp = type_map_.size_get();
    bool increase = false;
    for (auto& elt : e.decs_get())
      {
        if (type_map_.contains(elt->name_get()))
          increase = true;
        visit_dec_header(*elt);
        if (tmp + 1 != type_map_.size_get() && !increase)
        {
          redefinition(*elt, *type_map_.get(elt->name_get()));
          return;
        }
        if (increase)
          ++tmp;
        increase = false;
      }
    for (auto& elt : e.decs_get())
      {
        this->scope_begin();
        visit_dec_body(*elt);
        this->scope_end();
      }
  }

  template <class D>void Binder::func_chunk_visit(ast::Chunk<D>& e)
  {
    int tmp = func_map_.size_get();
    bool increase = false;
    for (auto& elt : e.decs_get())
      {
        if (func_map_.contains(elt->name_get()))
          increase = true;
        visit_dec_header(*elt);
        if (tmp + 1 != func_map_.size_get() && !increase)
        {
          redefinition(*elt, *func_map_.get(elt->name_get()));
          return;
        }
        if (increase)
          ++tmp;
        increase = false;
      }
    for (auto& elt : e.decs_get())
      {
        this->scope_begin();
        visit_dec_body(*elt);
        this->scope_end();
      }
  }

  template <class D>void Binder::var_chunk_visit(ast::Chunk<D>& e)
  {    
    for (auto& elt : e.decs_get())
      {
        visit_dec_header(*elt);
      }

    for (auto& elt : e.decs_get())
      {
        this->scope_begin();
        visit_dec_body(*elt);
        this->scope_end();
      }
  }

  /// Check a Function or Type declaration header.
  template <> inline void Binder::visit_dec_header(ast::VarDec& e)
  {
    var_map_.put(e.name_get(), &e);

    if (e.type_name_get() != nullptr)
      e.type_name_get()->accept(*this);
  }

  /// Check a Function or Type declaration body.
  template <> inline void Binder::visit_dec_body(ast::VarDec& e)
  {
    if (e.init_get() != nullptr)
      e.init_get()->accept(*this);
  }

  /* These specializations are in bind/binder.hxx, so that derived
     visitors can use them (otherwise, they wouldn't see them).  */

  // DONE: Some code was deleted here.
  /// Check a Function or Type declaration header.
  template <> inline void Binder::visit_dec_header(ast::FunctionDec& e)
  {
    func_map_.put(e.name_get(), &e);

    if (e.result_get() != nullptr)
      e.result_get()->accept(*this);
  }

  /// Check a Function or Type declaration body.
  template <> inline void Binder::visit_dec_body(ast::FunctionDec& e)
  {
    int tmp = var_map_.size_get();
    int size = 0;
    for (auto& elt: e.formals_get())
      ++size;
    e.formals_get().accept(*this);
    if (tmp + size != var_map_.size_get())
    {
      redefinition(*var_map_.get(e.name_get()), *var_map_.get(e.name_get()));
      return;
    }

    if (e.body_get() != nullptr)
      e.body_get()->accept(*this);
  }

  /// Check a Function or Type declaration header.
  template <> inline void Binder::visit_dec_header(ast::TypeDec& e)
  {
    type_map_.put(e.name_get(), &e);
  }

  /// Check a Function or Type declaration body.
  template <> inline void Binder::visit_dec_body(ast::TypeDec& e)
  {
    e.ty_get().accept(*this);
  }

} // namespace bind
