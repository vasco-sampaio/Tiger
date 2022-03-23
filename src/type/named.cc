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

  // FIXME: Some code was deleted here (Inherited functions).

  const Type& actual() const
  {

  }

  void accept(ConstVisitor& v) const
  {

  }

  void accept(Visitor& v)
  {
    
  }

  // FIXME: Some code was deleted here (Sound).
  Named::bool sound() const
  {
    
  }

  // FIXME: Some code was deleted here (Special implementation of "compatible_with" for Named).
  bool Named::compatible_with(const Type& other) const
  {

  }

} // namespace type