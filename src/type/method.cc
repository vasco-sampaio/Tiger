/**
 ** \file type/method.cc
 ** \brief Implementation for type/method.hh.
 */

#include <iostream>

#include <type/method.hh>
#include <type/visitor.hh>

namespace type
{
  Method::Method(misc::symbol name,
                 const Class* owner,
                 const Record* formals,
                 const Type& result,
                 ast::MethodDec* def)
    : Function(formals, result)
    , name_(name)
    , owner_(owner)
    , def_(def)
  {}

  void Method::accept(ConstVisitor& v) const { v(*this); }

  void Method::accept(Visitor& v) { v(*this); }

  // DONE: Some code was deleted here.
  bool compatible_with(const Type& other) const
  {
    auto fun = dynamic_cast<const Method*>(&other);
    if (fun == nullptr || owner_get() != fun->owner_get())
      return false;
    if (!formals_->compatible_with(fun->formals_get()) || !result_.compatible_with(fun->result_get()))
      return false;
    return true;
  }

} // namespace type
