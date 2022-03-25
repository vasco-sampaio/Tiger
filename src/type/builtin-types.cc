/**
 ** \file type/builtin-types.cc
 ** \brief Implementation for type/builtin-types.hh.
 */

#include <ostream>

#include <type/builtin-types.hh>
#include <type/visitor.hh>
#include <type/named.hh>

namespace type
{
  // DONE: Some code was deleted here (Int, String, Void).

  bool Int::compatible_with(const Type& other) const
  {
    auto x = dynamic_cast<const Int*>(&other);
    if (x == nullptr)
    {
      auto y = dynamic_cast<const Named*>(&other);
      if (y != nullptr)
        return this->compatible_with(*(y->type_get()));
    }
    return x != nullptr;
  }
  bool String::compatible_with(const Type& other) const
  {
    auto x = dynamic_cast<const String*>(&other);
    if (x == nullptr)
    {
      auto y = dynamic_cast<const Named*>(&other);
      if (y != nullptr)
        return this->compatible_with(*(y->type_get()));
    }
    return x != nullptr;
  }
  bool Void::compatible_with(const Type& other) const
  {
    auto x = dynamic_cast<const Void*>(&other);
    if (x == nullptr)
    {
      auto y = dynamic_cast<const Named*>(&other);
      if (y != nullptr)
        return this->compatible_with(*(y->type_get()));
    }
    return x != nullptr;
  }

    void Int::accept(ConstVisitor&) const
    {}
    void Int::accept(Visitor&)
    {}

    void String::accept(ConstVisitor&) const
    {}
    void String::accept(Visitor&)
    {}

    void Void::accept(ConstVisitor&) const
    {}
    void Void::accept(Visitor&)
    {}
  
} // namespace type
