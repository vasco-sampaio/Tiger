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

  // DONE: Some code was deleted here (Error reporting).
  template <typename T>
  void Binder::undeclared(const std::string& k, const T& e)
  {
    error_ << misc::error::error_type::bind << e.location_get() << k
           << " : undeclared " << e.name_get() << '\n';
  }

  template <typename T>
  void Binder::redefinition(const T& e1, const T& e2)
  {
    error_ << misc::error::error_type::bind << e2.location_get()
           << " : redefinition: " << e2.name_get() << '\n'
           << e1.location_get() << ": first definition\n";
  }

  void Binder::outside_break(const ast::BreakExp& e)
  {
    error_ << misc::error::error_type::bind << e.location_get()
           << ": `break' outside any loop\n";
  }

  void Binder::check_main(const ast::FunctionDec& e)
  {
    // DONE: Some code was deleted here.

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

  // DONE: Some code was deleted here

  void Binder::operator()(ast::LetExp& e)
  {
    this->scope_begin();
    e.decs_get()->accept(*this);
    if (e.body_get() != nullptr)
      e.body_get()->accept(*this);
    this->scope_end();
  }

  void Binder::operator()(ast::CallExp& e)
  {
    try
      {
        e.def_set(func_map_.get(e.name_get()));
      }
    catch (std::range_error)
      {
        undeclared("function", e);
      }
    for (auto& x : e.args_get())
      x->accept(*this);
  }

  void Binder::operator()(ast::SimpleVar& e)
  {
    try
      {
        e.def_set(var_map_.get(e.name_get()));
      }
    catch (std::range_error)
      {
        undeclared("variable", e);
      }
  }

  void Binder::operator()(ast::WhileExp& e)
  {
    loop_vec_.push_back(&e);
    e.def_set_exp(&e);
    e.test_get().accept(*this);

    in_body++;
    e.body_get().accept(*this);
    in_body--;

    loop_vec_.pop_back();
  }

  void Binder::operator()(ast::ForExp& e)
  {
    loop_vec_.push_back(&e);
    e.def_set_exp(&e);

    visit_dec_header(e.vardec_get());
    visit_dec_body(e.vardec_get());

    e.hi_get().accept(*this);

    in_body++;
    e.body_get().accept(*this);
    in_body--;

    loop_vec_.pop_back();
  }

  void Binder::operator()(ast::BreakExp& e)
  {
    if (loop_vec_.size() == 0 || !in_body)
    {
      outside_break(e);
      return;
    }
    e.def_set_exp(*(loop_vec_.end() - 1));
  }

  void Binder::operator()(ast::NameTy& e)
  {
    try
      {
        e.def_set(type_map_.get(e.name_get()));
      }
    catch (std::range_error)
      {
        undeclared("type", e);
      }
  }

    /*-------------------.
  | Visiting VarChunk. |
  `-------------------*/

    // DONE: Some code was deleted here.
    void Binder::operator()(ast::VarChunk& e)
  {
    int save = in_body;
    in_body = 0;
    var_chunk_visit<ast::VarDec>(e);
    in_body = save;
  }

  /*------------------------.
  | Visiting FunctionChunk. |
  `------------------------*/

  // DONE: Some code was deleted here.
  void Binder::operator()(ast::FunctionChunk& e)
  {
    int save = in_body;
    in_body = 0;
    func_chunk_visit<ast::FunctionDec>(e);
    in_body = save;
  }

  /*--------------------.
  | Visiting TypeChunk. |
  `--------------------*/
  // DONE: Some code was deleted here.
  void Binder::operator()(ast::TypeChunk& e) 
  { 
    int save = in_body;
    in_body = 0;
    chunk_visit<ast::TypeDec>(e);
    in_body = save;
  }

} // namespace bind
