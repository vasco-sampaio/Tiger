/**
 ** \file type/builtin-types.cc
 ** \brief Implementation for type/builtin-types.hh.
 */

#include <ostream>

#include <type/builtin-types.hh>
#include <type/visitor.hh>

namespace type
{
  // DONE: Some code was deleted here (Int, String, Void).

  bool Int::compatible_with(const Type& other) const
  {
    auto x = dynamic_cast<const Int*>(&other);
    return x != nullptr;
  }
  bool String::compatible_with(const Type& other) const
  {
    return dynamic_cast<const String*>(&other) != nullptr;
  }
  bool Void::compatible_with(const Type& other) const
  {
    return dynamic_cast<const Void*>(&other) != nullptr;
  }
  
} // namespace type