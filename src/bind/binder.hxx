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
    int tmp = 0;
    std::map<misc::symbol, int> err_check_map {};
    for (auto& elt : e.decs_get())
      {
        visit_dec_header(*elt);
        err_check_map.insert({elt->name_get(), tmp});
        if (err_check_map.size() != tmp + 1)
        {
          redefinition(*elt, *type_map_.get(elt->name_get()));
          return;
        }
        ++tmp;
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
    int tmp = 0;
    std::map<misc::symbol, int> err_check_map {};
    for (auto& elt : e.decs_get())
      {
        visit_dec_header(*elt);
        err_check_map.insert({elt->name_get(), tmp});
        if (err_check_map.size() != tmp + 1)
        {
          redefinition(*elt, *func_map_.get(elt->name_get()));
          return;
        }
        ++tmp;
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
    int tmp = 0;
    std::map<misc::symbol, int> err_check_map {};
    for (auto& elt : e.decs_get())
      {
        visit_dec_header(*elt);
        err_check_map.insert({elt->name_get(), tmp});
        if (err_check_map.size() != tmp + 1)
          {
            redefinition(*elt, *var_map_.get(elt->name_get()));
            return;
          }
        ++tmp;
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
    e.formals_get().accept(*this);

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
