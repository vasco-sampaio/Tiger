/**
 ** \file type/named.cc
 ** \brief Implementation for type/named.hh.
 */

#include <set>

#include <type/named.hh>
#include <type/visitor.hh>

namespace type
{
  Named::Named(misc::symbol name)
    : name_(name)
    , type_(nullptr)
  {}

  Named::Named(misc::symbol name, const Type* type)
    : name_(name)
    , type_(type)
  {}

  // DONE: Some code was deleted here (Inherited functions).

  void Named::accept(ConstVisitor& v) const
  {
    v(*this);
  }

  void Named::accept(Visitor& v)
  {
    v(*this);
  }

  // DONE: Some code was deleted here (Sound).
  bool Named::sound() const
  {
    auto x = dynamic_cast<const Named*>(type_);
    if (x == nullptr)
      return type_ != this;
    auto cur = x->type_get();
    while (cur != this)
    {
      auto tmp = dynamic_cast<const Named*>(cur);
      if (tmp == nullptr)
        return true;
      cur = tmp->type_get();
    }
    return false;
  }

  // DONE: Some code was deleted here (Special implementation of "compatible_with" for Named).
  bool Named::compatible_with(const Type& other) const
  {
    auto x = dynamic_cast<const Named*>(&other);
    if (x != nullptr)
      return type_->compatible_with(*(x->type_));
    return type_->compatible_with(other);
  }

} // namespace type
