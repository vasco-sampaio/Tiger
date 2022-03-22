/**
 ** \file escapes/escapes-visitor.cc
 ** \brief Implementation for escapes/escapes-visitor.hh.
 */

#include <ast/all.hh>
#include <escapes/escapes-visitor.hh>
#include <misc/contract.hh>

namespace escapes
{
  // DONE: Some code was deleted here.
  void EscapesVisitor::operator()(ast::VarDec& e)
  {
    e.escape_set(false);
    (scopes_.end() - 1)->push_back(std::pair(e.name_get(), &e));
    super_type::operator()(e);
  }

  void EscapesVisitor::operator()(ast::SimpleVar& e)
  {
    auto last_scope = scopes_.end() - 1;
    bool found = false;
    for (auto& x : *last_scope)
    {
      if (x.first == e.name_get())
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      for (auto& x : scopes_)
      {
        for (auto& y : x)
        {
          if (y.first == e.name_get())
            {
              y.second->escape_set(true);
            }
        }
      }
    }
    super_type::operator()(e);
  }

  void EscapesVisitor::operator()(ast::FunctionDec& e)
  {
    scopes_.push_back(std::vector<std::pair<misc::symbol, ast::VarDec*>>());
    super_type::operator()(e);
    scopes_.pop_back();
  }

} // namespace escapes
