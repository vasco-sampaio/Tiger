/**
 ** \file type/nil.cc
 ** \brief Implementation for type/nil.hh.
 */

#include <ostream>

#include <type/class.hh>
#include <type/nil.hh>
#include <type/record.hh>
#include <type/visitor.hh>

namespace type
{
  /*------.
  | Nil.  |
  `------*/

  void Nil::accept(ConstVisitor& v) const { v(*this); }

  void Nil::accept(Visitor& v) { v(*this); }

  bool Nil::compatible_with(const Type& other) const
  {
    // DONE: Some code was deleted here.
    if (dynamic_cast<const Nil*>(&other) != nullptr)
      return true;
    if (dynamic_cast<const Record*>(&other) != nullptr)
      return true;
    if (dynamic_cast<const Class*>(&other) != nullptr)
      return true;
    auto named = dynamic_cast<const Named*>(&other);
    if (named != nullptr)
      return compatible_with(*(named->type_get()));
    return false;
  }

  const Type* Nil::record_type_get() const { return record_type_; }

  void Nil::record_type_set(const Type& type) const { record_type_ = &type; }

} // namespace type
