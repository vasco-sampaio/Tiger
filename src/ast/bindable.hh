#pragma once

#include <ast/exp.hh>
#include <variant>

namespace ast
{
  class Bindable
  {
  public:
    Bindable()
      : def_(nullptr)
    {}

    void def_set(ast::Dec* def) { def_ = def; }
    
    void def_set_exp(std::variant<ast::WhileExp*, ast::ForExp*> def) { def_exp_ = def; }

    ast::Dec* def_get() const { return def_; }
    ast::Dec* def_get() { return def_; }

    std::variant<ast::WhileExp*, ast::ForExp*> def_get_exp() const { return def_exp_; }
    std::variant<ast::WhileExp*, ast::ForExp*> def_get_exp() { return def_exp_; }

  protected:
    ast::Dec* def_;
    std::variant<ast::WhileExp*, ast::ForExp*> def_exp_;
  };
} // namespace ast