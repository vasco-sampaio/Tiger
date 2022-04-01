/**
 ** \file type/array.cc
 ** \brief Implementation for type/array.hh.
 */

#include <type/array.hh>
#include <type/visitor.hh>

namespace type
{
  // DONE: Some code was deleted here.

  Array::Array(const Type& elements_type)
    : elements_type_(elements_type)
  {}

  void Array::accept(ConstVisitor& v) const { v(*this); }
  void Array::accept(Visitor& v) { v(*this); }


  bool Array::compatible_with(const Type& other) const
  {
    auto arr = dynamic_cast<const Array*>(&other);
    if (arr == nullptr)
      return false;
    return elements_type_get().compatible_with(arr->elements_type_get());
  }

} // namespace type
